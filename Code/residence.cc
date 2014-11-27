//
//  residence.cc
//  
//
//  Created by Galen Wray on 2014-11-20.
//
//

#include "residence.h"
#include "player.h"
#include <iostream>


using namespace std;

// Constructor
Residence::Residence(string name, int sqrNum, int numSiblings, int purchaseCost,string block, int * rent): Building(name, sqrNum, numSiblings, purchaseCost, block){
    for (int i = 0; i < 4; i++){
        this->rent[i] = rent[i];
    }
}



//Get private values
int Residence::getPay(){
    return rent[getOwner()->buildingCatalogue["Residence"] - 1]; // rent depends on the number of residences owned
}



// Change private values
void Residence::mortgage(){
    if (!mortgaged){
        getOwner()->trade(0, getPurchaseCost() / 2);
        mortgaged = true;
        cout << getName() << " has been mortgaged." << endl;
    }
    else cout << getName() << " has already been mortgaged." << endl;
}

void Residence::purchase(Player* p){
    if (!isOwned()){
        
        changeOwner(p, true);
        getOwner()->trade(getPurchaseCost(), 0);
        
        getOwner()->buildingCatalogue["Res"]++; // check first?
        cout << p->getName() << " bought " << getName() << "." << endl;
    }
    
}

void Residence::pay(Player *p){
    if (!mortgaged){
        p->trade(rent[getOwner()->buildingCatalogue["Res"] - 1], 0); // player pays owner
        getOwner()->trade(0, rent[getOwner()->buildingCatalogue["Res"] - 1]); // owner receives money from owner
        cout << p->getName() << " paid " << getOwner()->getName() << " $" << rent[getOwner()->buildingCatalogue["Res"] - 1] << " in rent." << endl;
    }
    else {
        cout << getName()<< " is mortgaged. No tuition is required." << endl;
    }
    
}


int Residence::getImprovementCost(){ return 0; }
int Residence::getImprovementLevel() { return 0; }
void Residence::improve(int numImprovments) { cout << "Error. You cannot add improvements to a Residence." << endl; }


