//
//  residence.h
//  
//
//  Created by Galen Wray on 2014-11-18.
//
//

#ifndef _residence_h
#define _residence_h

#include "building.h"

#include <string>

class Player;

class Residence: public Building {
    int rent[4];
    
public:
    Residence(std::string name, int sqrNum, int numSiblings, int purchaseCost, std::string block, int currRent, bool owned, bool mortgaged, Player* owner, int rent*);
    
    // Get private values
    int getRent(); // check to see if player can afford rent
    
    // Change private values
    void mortgage();
    void purchase(Player* p);
    void pay(Player *p);
    
};




#endif
