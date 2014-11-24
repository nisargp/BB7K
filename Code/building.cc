//
//  building.cc
//  
//
//  Created by Galen Wray on 2014-11-20.
//
//

#include "building.h"
#include <iostream>

using namespace std;



// Constructor
Building::Building(string name, int sqrNum, int numSiblings, int purchaseCost,bool owned, bool mortgaged, Player* owner, string block)
        : Square(name, sqrNum), numSiblings(numSiblings), purchaseCost(purchaseCost), owned(owned), mortgaged(mortgaged), p(owner), block(block){}



// Get protected values
int Building::getPurchaseCost() { return purchaseCost; }

string Building::getBlock(){ return block; }

bool Building::isOwned(){ return owned; }

bool Building::isMortgaged() { return mortgaged; }




// Change protected values
void Building::unmortgage(){
    if (mortgaged) {
        // owner pays half the price of the building + 10% (note: is it 10% of half of the price?)
        owner->trade((purchaseCost / 2) + (purchaseCost * 110), 0);
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
    cout<<"You have landed on: " << this->name << "." << endl;
    
    if (owned) {
        if(owner != this) p->pay();
    }
    else p->buyProperty();

}