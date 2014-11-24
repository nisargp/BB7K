//
//  gym.cc
//  
//
//  Created by Galen Wray on 2014-11-20.
//
//

#include "gym.cc"

#include <cstdlib>
#include <iostream>

using namespace std;


// Constructor
Gym::Gym(string name, int sqrNum, int numSiblings, int purchaseCost, bool owned, bool mortgaged, Player* owner, string block, bool bothOwned): Building(name, sqrNum, numSiblings, purchaseCost, owned, mortgaged, owner, block), currRent(0), bothOwned(bothOwned){}




// Get private values
int Gym::getRent(){
    int roll;
    
    roll = (rand % 6 + 1) + (rand % 6 + 1);
    
    if (bothOwned) currRent = 10 * roll; // 10 times the roll if both are owned
    else currRent = 4 * roll; // 4 times the roll if both are owned
    
    return currRent;
}



// Change private values
void::Gym::mortgage(){
    if (!mortgaged){
        owner->trade(0, getPurchaseCost/2);
        mortgaged = true;
        cout << getName() << " has been mortgaged." << endl;
    }
    else cout << getName() << " has already been mortgaged." << endl;
}


void Gym::pay(Player *p){
    if (!mortgaged){
        if (currRent == 0){
            int i = getRent();
        }
        p->trade(currRent, 0);
        owner->trade(0, currRent);
        currRent = 0;
        cout << p->getName() << " paid a usage fee of $" << rent[owner->buildingCatalogue["Residence"]] << " to " << owner->getName() << "." << endl;
    }
    else {
        cout << getName() << " is mortgaged. No usage fee is required." << endl;
    }
}


void Gym::purchase(Player* p){
    if (!owned){
        owner->trade(purchaseCost, 0);
        
        owned = true;
        owner = p;
        
        owner->buildingCatalogue[gym]++; // check?
        if (p->buildingCatalogue[gym] == numSiblings) bothOwned== true;
    }
    cout << p->getName() << " bought " << getName() << "." << endl;
}



