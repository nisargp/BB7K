//
//  residence.h
//  
//
//  Created by Galen Wray on 2014-11-18.
//
//

#ifndef _residence_h
#define _residence_h

#including "building.h"
class Player;

class Residence: public Building {
   // int numResidencesOwned; // number of residences owned by the owner
    int rent[4];
    
public:
    Residence(std::string name, int sqrNum, int numSiblings, int purchaseCost, int currRent, bool owned, bool mortgaged, Player* owner, int rent*);
    void mortgage();
    void purchase(Player* p);
    void pay(Player *p);
    int getRent(); // check to see if player can afford rent
};




#endif
