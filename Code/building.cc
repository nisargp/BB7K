//
//  building.cc
//  
//
//  Created by Galen Wray on 2014-11-20.
//
//

#include "building.h"
#include "player.h"
#include <iostream>

using namespace std;



// Constructor
Building::Building(string name, int sqrNum, int numSiblings, int purchaseCost, string block)
        : Square(name, sqrNum), numSiblings(numSiblings), purchaseCost(purchaseCost), owned(false), mortgaged(false), owner(NULL), block(block){}



// Get protected values
int Building::getPurchaseCost() { return purchaseCost; }

string Building::getBlock(){ return block; }

bool Building::isOwned(){ return owned; }

bool Building::isMortgaged() { return mortgaged; }


Player* Building::getOwner() { return owner; }



// Change protected values
void Building::unmortgage(){
    if (mortgaged) {
        owner->trade((purchaseCost / 2) * 110, 0);
        mortgaged = false;
        cout << "You have unmortgaged " << getName() << "." << endl;
    }
    else {
        cout << getName() << " must be mortgaged before unmortgaging." << endl;
    }


}

void Building::changeOwner(Player *p, bool owned) { // owned = false means the property is being returned to the bank
    owner = p;
    this->owned = owned;
}



// Method for each time you land on a square
void Building::land(Player *p){
    cout<<"You have landed on: " << getName() << "." << endl;
    
    if (owned) {
        if(owner != p) p->payPlayer(this);
    }
    else p->buyProperty(this);

}