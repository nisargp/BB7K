//
//  gym.cc
//  
//
//  Created by Galen Wray on 2014-11-20.
//
//

#include "gym.h"
#include "player.h"

#include <cstdlib>
#include <iostream>

using namespace std;


// Constructor
Gym::Gym(string name, int sqrNum, int numSiblings, int purchaseCost, string block): Building(name, sqrNum, numSiblings, purchaseCost, block), currRent(0), bothOwned(false){}




// Get private values
int Gym::getPay(){
    int roll;
    
    roll = (rand() % 6 + 1) + (rand() % 6 + 1);
    
    if (bothOwned) currRent = 10 * roll; // 10 times the roll if both are owned
    else currRent = 4 * roll; // 4 times the roll if both are owned
    
    return currRent;
}



// Change private values
void::Gym::mortgage(){
    if (!mortgaged){
        getOwner()->trade(0, getPurchaseCost()/2);
        mortgaged = true;
        cout << getName() << " has been mortgaged." << endl;
    }
    else cout << getName() << " has already been mortgaged." << endl;
}


void Gym::pay(Player *p){
    if (!mortgaged){
        if (currRent == 0){
            int i = getPay();
        }
        p->trade(currRent, 0);
        getOwner()->trade(0, currRent);
        cout << p->getName() << " paid a usage fee of $" << currRent << " to " << getOwner()->getName() << "." << endl;
        currRent = 0;
    }
    else {
        cout << getName() << " is mortgaged. No usage fee is required." << endl;
    }
}


void Gym::purchase(Player* p){
    if (!isOwned()){
        getOwner()->trade(getPurchaseCost(), 0);
        
        changeOwner(p, true);
        
        getOwner()->buildingCatalogue["Gym"]++; // check?
        if (p->buildingCatalogue["Gym"] == numSiblings) bothOwned = true;
    }
    cout << p->getName() << " bought " << getName() << "." << endl;
}


void Gym::changeOwner(Player *p, bool owned){
    owner = p;
    this->owned = owned;
    if (owner && owner->buildingCatalogue[block] == numSiblings) bothOwned = true;
    else bothOwned = false;
}





int Gym::getImprovementCost(){ return 0; }
int Gym::getImprovementLevel() { return 0; }
void Gym::improve(int numImprovments) { cout << "Error. You cannot add improvements to a Gym." << endl; }
