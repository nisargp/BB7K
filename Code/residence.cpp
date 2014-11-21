//
//  residence.cc
//  
//
//  Created by Galen Wray on 2014-11-20.
//
//

#include "residence.cc"


using namespace std;

Residence::Residence(string name, int numSiblings, int purchaseCost, int * rent): Building(name, numSiblings, purchaseCost){
    for (int i = 0; i < 4; i++){
        this->rent[i] = rent[i];
    }
}


void Residence::mortgage(){
    owner->trade(0, purchaseCost/2);
    mortgaged = true;
    cout << name << " has been mortgaged." << endl;
}

void Residence::purchase(Player* p){
    if (!owned){
        owner->trade(purchaseCost, 0);
        
        owned = true;
        owner = p;
        
        owner->buildingCatalogue[residence]++;
    }
}

void Residence::pay(Player *p){
    if (!mortgaged){
        p->trade(rent[owner->buildingCatalogue[residence]], 0);
        owner->trade(0, rent[owner->buildingCatalogue[residence]]);
    }
    else {
        cout << "The building is mortgaged. No tuition is required." << endl;
    }
    
}

int Residence::getRent(){
    return rent[owner->buildingCatalogue[residence]];
}

