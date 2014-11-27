//
//  player.cc
//  
//
//  Created by Galen Wray on 2014-11-23.
//
//

#include "player.h"
#include "square.h"
#include "gameboard.h"
#include "computer.h"
#include "building.h"
#include "academic.h"
#include "residence.h"
#include "gym.h"
#include "RUTRCup.h"
#include "textdisplay.h"
#include <cstdlib>

using namespace std;

// Constructor
Player::Player(string name, char piece, int money, Square* currPosition, int numAssets, Building ** property, RUTRCup ** cup, int numCups, bool DCTimsLine, int numTurnsDC, int payOut, bool bankruptcy, TextDisplay *td)
: name(name), piece (piece), money (money), currPosition(currPosition), numAssets(numAssets), numCups(numCups), DCTimsLine(DCTimsLine), numTurnsDC(numTurnsDC), payOut(payOut), bankruptcy(bankruptcy), td(td){
    
    for (int i = 0; i < numAssets; i++){
        this->property[i] = property[i];
        buildingCatalogue[property[i]->getBlock()]++;
        
    }
    for (int i = 0; i < numCups; i++){
        this->cup[i] = cup[i];
    }
    
    g = Gameboard::getInstance();
    g->addPlayer(this);
    
}


// Notify text display to move player on board
void Player::notify(){
    td->notify(name, currPosition->getName()); // should we send the character instead of the name?
}


// Get methods
int Player::getTotalWorth(){
    int totalWorth = money; // money
    
    for (int i = 0; i < numAssets; i++){
        totalWorth+= property[i]->getPurchaseCost(); // + cost of properties
        
        Academic * prop = dynamic_cast<Academic*>(property[i]);
        if (prop){ // which library for dynamic casting?
            totalWorth += (prop->getImprovementLevel() * prop->getImprovementCost()); // + improvements
        }
    }
    return totalWorth;
}

string Player::getName(){ return name; }

int Player::getMoney() { return money; }



// Add Methods
void Player::addCup(RUTRCup * cup){
    this->cup[numCups] = cup;
    numCups++;
}


//Gameplay

// Roll
void Player::roll(int move){
    int newSquare = currPosition->getSquareNum() + move;
    if (newSquare > 39){
        newSquare -= 40;
        cout << "You have passed Collect OSAP and collected $200." << endl;
        trade(0,200);
    }
    currPosition = g->getSquare(newSquare);
    notify();
    currPosition->land(this);
}


// Trade (int, int)
void Player::trade(int give, int receive){
    
    // Checks to see if they have enough money
    // Otherwise, sees if they want to declare bankruptcy
    if (money + receive >= give){
        money = money - give + receive;
    }
    else {
        payOut = give - receive;
        pay();
    }
}

// Trade (string, int)
void Player::trade(string give, int receive){ // before calling, you must already check to see that there are no improvements for the block
    
    bool found = false;
    for (int i = 0; i < numAssets; i++){
        // Removes property from owner's list of assets
        if (!found && property[i]->getName() == give){
            buildingCatalogue[property[i]->getBlock()]--;
            numAssets--;
        }
        // shifts property array
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
void Player::trade(int give, string receive){ // before calling, you must already check to see that there are no improvements for the block
    money -= give;
    
    Building * r = dynamic_cast<Building*> (g->getSquare(receive)); // finds pointer for property
    
    property[numAssets] = r; // adds to array
    numAssets++;
    buildingCatalogue[r->getBlock()]++;
    property[numAssets-1]->changeOwner(this);
    
    // See if they need to unmortgage property
    if (property[numAssets-1]->isMortgaged()){
        unmortgageTorB(property[numAssets-1]);
    }
    
    if(buildingCatalogue[r->getBlock()] == g->getNumSiblings (r->getBlock())) improvements(property[numAssets-1]);
}


// Trade (string, string)
void Player::trade(string give, string receive){
    
    // give
    bool found = false;
    for (int i = 0; i < numAssets; i++){
        // Removes property from owner's list of assets
        if (!found && property[i]->getName() == give){
            buildingCatalogue[property[i]->getBlock()]--;
            numAssets--;
        }
        // shifts property array
        if (found){
            if (i + 1 < numAssets){
                property[i] = property[i+1];
            } else {
                property[i] = NULL;
            }
        }
    }
    
    // receive
    Building * r = dynamic_cast<Building*> (g->getSquare(receive)); // finds pointer for property
    
    property[numAssets] = r; // adds to array
    numAssets++;
    buildingCatalogue[r->getBlock()]++;
    property[numAssets-1]->changeOwner(this);
    
    // See if they need to unmortgage property
    if (property[numAssets-1]->isMortgaged()){
        unmortgageTorB(property[numAssets-1]);
    }
    
    if(buildingCatalogue[r->getBlock()] == g->getNumSiblings (r->getBlock())) improvements(property[numAssets-1]);
}



// Owe money to a player
void Player::declareBankruptcy(Player *p){
    cout << name << " has declared bankruptcy." << endl;
    
    p->trade(0, money);
    for (int i = 0; i < numAssets; i++){
        
        p->trade(0, property[i]->getName());
        p->buildingCatalogue[property[i]->getBlock()]++;
        property[i]->changeOwner(p);
        
        
        if (property[i]->isMortgaged()){
            unmortgageTorB(property[i]);
        }
        
        if(buildingCatalogue[property[i]->getBlock()] == g->getNumSiblings (property[i]->getBlock())) improvements(property[i]);
    }
           
    // do we give roll up the rim cups to other player or delete them?
    for (int i = 0; i < numCups; i++){
        delete cup[i];
    }
    
    g->removePlayer(this);
}


// Owe money (not to a player)
void Player::declareBankruptcy(){
    cout << name << " has declared bankruptcy." << endl;
    
    for (int i = 0; i < numAssets; i++){
        property[i]->unmortgage();
        property[i]->changeOwner(0, false);
        Academic * prop = dynamic_cast<Academic *>(property[i]);
        if (prop){
            while (prop->getImprovementLevel() != 0){
                prop->improve(-1);
            }
        }
    }
    
    for (int i = 0; i < numCups; i++){
        delete cup[i];
    }
    g->removePlayer(this);
}


void Player::printAssets(){
    cout << name << "'s Assets" << endl;
    for (int i = 0; i < numAssets; i++){
        string mortgaged;
        if (property[i]->isMortgaged()) mortgaged = "Mortgaged";
        else mortgaged = "Unmortgaged";
        cout<< property[i]->getName() << ": " << mortgaged << " Purchase Cost - $" << property[i]->getPurchaseCost() << endl;
    }
}



Player::~Player(){
    for (int i = 0; i < numCups; i++){
        delete cup[i];
    }
}




