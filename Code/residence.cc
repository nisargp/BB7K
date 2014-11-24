//
//  residence.cc
//  
//
//  Created by Galen Wray on 2014-11-20.
//
//

#include "residence.cc"
#include <iostream>


using namespace std;

// Constructor
Residence::Residence(string name, int sqrNum, int numSiblings, int purchaseCost,bool owned, bool mortgaged, Player* owner, string block, int * rent): Building(name, sqrNum, numSiblings, purchaseCost, owned, mortgaged, owner, block){
    for (int i = 0; i < 4; i++){
        this->rent[i] = rent[i];
    }
}



//Get private values
int Residence::getRent(){
    return rent[owner->buildingCatalogue["Residence"]]; // rent depends on the number of residences owned
}



// Change private values
void Residence::mortgage(){
    if (!mortgaged){
        owner->trade(0, getPurchaseCost() / 2);
        mortgaged = true;
        cout << getName << " has been mortgaged." << endl;
    }
    else cout << getName() << " has already been mortgaged." << endl;
}

void Residence::purchase(Player* p){
    if (!owned){
        owner->trade(purchaseCost, 0);
        
        owned = true;
        owner = p;
        
        owner->buildingCatalogue[residence]++; // check first?
        cout << p->getName() << " bought " << getName() << "." << endl;
    }
    
}

void Residence::pay(Player *p){
    if (!mortgaged){
        p->trade(rent[owner->buildingCatalogue["Residence"]], 0); // player pays owner
        owner->trade(0, rent[owner->buildingCatalogue["Residence"]]); // owner receives money from owner
        cout << p->getName() << " paid " << owner->getName() << " $" << rent[owner->buildingCatalogue["Residence"]] << " in rent." << endl;
    }
    else {
        cout << getName()<< " is mortgaged. No tuition is required." << endl;
    }
    
}





