//
//  building.cc
//  
//
//  Created by Galen Wray on 2014-11-20.
//
//

#include "building.h"

using namespace std;


Building::Building(string name, int numSiblings, int purchaseCost)
        : Square(name), numSiblings(numSiblings), purchaseCost(purchaseCost), owned(false), mortgaged(false), p(NULL){}

bool Building::isOwned(){ return owned; }

bool Building::isMortgaged() { return mortgaged; }

void Building::unmortgage(){
    owner->trade((purchaseCost / 2) * 110, 0); // owner pays half the price of the building + 10% (note: is it 10% of half of the price?)
    mortgaged = false;
}

int Building::getPurchaseCost() { return purchaseCost; }
