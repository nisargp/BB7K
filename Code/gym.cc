//
//  gym.cc
//  
//
//  Created by Galen Wray on 2014-11-20.
//
//

#include "gym.cc"

#include <cstdlib>

using namespace std;


Gym::Gym(string name, int numSiblings, int purchaseCost): Building(name, numSiblings, purchaseCost), currRent(0), bothOwned(false){}


void::Gym::mortgage(){
    owner->trade(0, purchaseCost/2);
    mortgaged = true;
    cout << name << " has been mortgaged." << endl;
}


void Gym::pay(Player *p){
    if (!mortgaged){
        if (currRent == 0){
            int i = getRent();
        }
        p->trade(currRent, 0);
        owner->trade(0, currRent);
        currRent = 0;
    }
    else {
        cout << "The building is mortgaged. No usage fee is required." << endl;
    }
}


void Gym::purchase(Player* p){
    if (!owned){
        owner->trade(purchaseCost, 0);
        
        owned = true;
        owner = p;
        
        owner->buildingCatalogue[gym]++;
        if (p->buildingCatalogue[gym] == numSiblings) bothOwned== true;
    }
}


int Gym::getRent(){
    int roll;
    
    roll = (rand % 6 + 1) + (rand % 6 + 1);
    
    if (bothOwned) currRent = 10 * roll;
    else currRent = 4 * roll;
    
    return currRent;
}
