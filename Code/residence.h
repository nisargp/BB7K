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
    int numResidencesOwned; // number of residences owned by the owner
    int tuition[4];
    
public:
    Residence();
    bool isOwned();
    bool isMortgaged();
    void mortgage();
    void unmortgage();
    int getPurchaseCost();
    void purchase(Player* p);
    void pay(Player *p);
    void getRent(); // check to see if player can afford rent
    ~Residence();
};




#endif
