//
//  player.cc
//  
//
//  Created by Galen Wray on 2014-11-23.
//
//

#include "player.h"
#include <cstdlib>


// Constructor
Player::Player(string name, char piece, int money, Square* currPosition, int numAssets, Square ** property, RUTRCUP ** cup, int numCups, bool DCTimsLine, int numTurnsDC, int payOut, bool bankruptcy)
: name(name), piece (piece), currPosition(currPosition), numAssets(numAssets), numCups(numCups), DCTimsLine(DCTimsLine), numTurnsDC(numTurnsDC), payOut(payOut), bankruptcy(bankruptcy){
    
    for (int i = 0; i < numAssets; i++){
        this->property[i] = property[i];
        buildingCatalogue[property->getBlock()]++;
        
    }
    for (int i = 0; i < numCups; i++){
        this->cup[i] = cup[i];
    }
    
    g = Gameboard::getInstance();
    
}


// Notify text display to move player on board
void Player::notify(){
    td->notify(name, p->currLocation->name); // should we send the character instead of the name?
}


// Get methods
int Player::getTotalWorth(){
    int totalWorth = money; // money
    
    for (int i = 0; i < numAssets; i++){
        totalWorth+= property[i]->getPurchaseCost(); // + cost of properties
        
        if (dynamic_cast<Academic*>(property[i])){ // which library for dynamic casting?
            totalWorth += (property[i]->getImprovementLevel * property[i]->getImprovementCost); // + improvements
        }
    }
    return totalWorth;
}

string Player::getName(){ return name; }

int Player::getMoney() { return money; }



// Add Methods
int Player::addCup(RUTRCUP * cup){
    this->cup[numCups] = cup;
    numCups++;
}


//Gameplay

// Roll
void Player::roll(int move){
    int newSquare = currLocation->getSquareNum + move;
    if (newSquare > 39){
        newSquare -= 40;
        cout << "You have passed Collect OSAP and collected $200." << endl;
        trade(0,200);
    }
    currLocation = g->getSquare(newSquare);
    notify();
    currLocation->land(this);
}


// Trade (int, int)
void Player::trade(int give, int receive){
    money = money - give + receive;
}

// Trade (string, int)
void Player::trade(string give, int receive){
    bool found = false;
    for (int i = 0; i < numAssets; i++){
        if (!found && property[i]->name == give){
            buildingCatalogue[property[i]->getBlock()]--;
            numAssets--;
        }
        if (found){
            if (i + 1 < numAssets){
                property[i] = property[i+1];
            } else {
                property[i] = NULL;
            }
        }
    }
    money += receive;
}

// Trade (int,string)
void Player::trade(int give, string receive){
    Square * r;
    
    for (int i = 0; i < 40; i++){
        r = g->getSquare[i];
        if (r->name == receive) {
            property[numAssets] = r;
            numAssets++;
            buildingCatalogue[r->getBlock()]--;
            break;
        }
    }
    money -= give;
}

// Trade (string, string)
void Player::trade(string give, string receive){
    // give
    bool found = false;
    for (int i = 0; i < numAssets; i++){
        if (!found && property[i]->name == give){
            buildingCatalogue[property[i]->getBlock()]--;
            numAssets--;
        }
        if (found){
            if (i + 1 < numAssets){
                property[i] = property[i+1];
            } else {
                property[i] = NULL;
            }
        }
    }
    
    // receive
    Square * r;
    
    for (int i = 0; i < 40; i++){
        r = g->getSquare[i];
        if (r->name == receive) {
            property[numAssets] = r;
            numAssets++;
            buildingCatalogue[r->getBlock()]--;
            break;
        }
    }
}



// Owe money to a player
void Player::declareBankruptcy(Player *p){
    p->trade(0, money);
    for (int i = 0; i < numAssets; i++){
        
        p->trade(0, property[i]->name);
        property[i]->changeOwner(p);
        
        if (property[i]->isMortgaged()){
            
            cout << property[i]->name << " is mortgaged. Would you like to unmortgage it? (Y/N)" << endl;
            
            string s;
            
            if (dynamic_cast<Computer*> (p)){
                if (p->getMoney() >= (p->purchaseCost/2 + p->purchaseCost *.1)) s == "Y";
                else s == "N";
            } else cin >> s;
            
            
            if (s == "Y"){
                property[i]->unmortgage();
            }
            else {
                p->trade(property[i]->getPurchaseCost * .1, 0);
            }
        }
    }
    // do we give roll up the rim cups to other player or delete them?
    for (int i = 0; i < numCups; i++){
        delete cup[i];
    }
}


// Owe money (not to a player)
void Player::declareBankruptcy(){
    for (int i = 0; i < numAssets; i++){
        property[i]->unmortgage();
        property[i]->changeOwner(0, false);
        while (property[i]->getImprovementLevel != 0){
            property[i]->improve(-1);
        }
    }
    
    for (int i = 0; i < numCups; i++){
        delete cup[i];
    }
}


Player::~Player(){
    for (int i = 0; i < numCups; i++){
        delete cup[i];
    }
}




