//
//  academic.cc
//  
//
//  Created by Galen Wray on 2014-11-20.
//
//

#include "academic.h"
#include "player.h"
#include "computer.h"
#include "textdisplay.h"
#include <iostream>

using namespace std;


// Constructor
Academic::Academic(string name, int sqrNum,int numSiblings, int purchaseCost, string block, int improvementCost, int *tuition, TextDisplay *td)
        : Building(name, sqrNum, numSiblings, purchaseCost, block), blockOwned(false), improvementCost(improvementCost), improvementLevel(0), td(td){
            for (int i = 0; i < 6; i++){
                this->tuition[i] = tuition[i];
            }
}



// Notify (Observer Pattern)
void Academic::notifyTextDisplay(int changeImprovements){
    td->notify(getName(), changeImprovements);
}



 // Get private values
int Academic::getPay(){
    if (!mortgaged) {
        if(improvementLevel == 0 && blockOwned){
            return tuition[improvementLevel] * 2; // Tuition will be twice the cost if a player owns the entire block
        }
        return tuition[improvementLevel];
    }
    else return 0;
}

int Academic::getImprovementCost(){ return improvementCost; }

int Academic::getImprovementLevel(){ return improvementLevel; }


// Change private values
void Academic::mortgage(){
    
    // Can only mortage without improvements
    if(improvementLevel != 0) {
        
        string s;
        
        if (dynamic_cast<Computer*>(getOwner())) s = "Y"; // change this to a method for computer & human
        else {
            cin>>s;
            cout<< "You must sell all improvements before mortgaging the property." << endl;
            cout<< "Would you like to continue? (Y/N)" << endl;
        }
        
        if (s == "N" || s == "n") return;
        
        while(improvementLevel != 0){
            improve(-1);
        }
    }
    if (!mortgaged){
        getOwner()->trade(0, getPurchaseCost()/2); // get 1/2 the purchase cost when mortgaging a building
        mortgaged = true;
        cout << getName() << " has been mortgaged." << endl;
    }
    else cout << getName() << " has already been mortgaged." << endl;
}


void Academic::pay(Player *p){
    if (!mortgaged){
        int pay;
        
        // tuition is twice the price if the entire block is owned (and there are no improvements
        if(improvementLevel == 0 && blockOwned){ pay = tuition[improvementLevel] * 2; }
        else { pay = tuition[improvementLevel]; }
        
        p->trade(pay, 0); // player pays owner
        getOwner()->trade(0, pay); // owner receives tuition
        cout << p->getName() << " paid " << getOwner()->getName() << " $" << pay << " in tuition." << endl;
    }
    else {
        cout << getName() << " is mortgaged. No tuition is required." << endl; // no payment if the building is mortgaged
    }
}


void Academic::improve(int numImprovments){
    if (!mortgaged){
    if (numImprovments == 1){ // add an improvement
        if (blockOwned){
            if (improvementLevel < 5){
                getOwner()->trade(improvementCost, 0);
                numImprovments++;
                notifyTextDisplay(numImprovments);
            }
            else cout << "You already have a maximum number of improvements on " << getName() << "." << endl;
        }
        else cout<< "You must own the entire block (" << getBlock() << ") to get improvements on " << getName() << "."<< endl;
        
    }
    else if (numImprovments == -1){ // remove an improvement
        if (numImprovments != 0){
            getOwner()->trade(0, improvementCost / 2); // get back only half the cost of an improvement
            numImprovments--;
            notifyTextDisplay(numImprovments);
        }
        else cout << "You don't have any improvements on " << getName() << " to remove." << endl;
    }
    }
}



void Academic::purchase(Player* p){
    if (!isOwned()){
        changeOwner(p, true);
        getOwner()->trade(getPurchaseCost(), 0);
        cout << p->getName() << " bought " << getName() << "." << endl;
        getOwner()->buildingCatalogue[block]++; // do you need to see if it exists first?
        if (p->buildingCatalogue[block] == numSiblings){
            blockOwned = true;
            owner->improvements(this);
        }
    }
}


void Academic::changeOwner(Player *p, bool owned){
    owner = p;
    this->owned = owned;
    if (owner && owner->buildingCatalogue[block] == numSiblings){
        blockOwned = true;
        owner->improvements(this);
    }
    else blockOwned = false;
}


