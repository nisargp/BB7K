//
//  gym.h
//  
//
//  Created by Galen Wray on 2014-11-18.
//
//

#ifndef _gym_h
#define _gym_h

#include "building.h"
class Player;

class Gym: public Building {
    bool bothOwned; // true if both buildings are owned by the owner
    int currRent;
    
public:
    Gym(string name, int numSiblings, int purchaseCost, int currRent);
    void mortgage();
    void purchase(Player* p);
    void pay(Player *p);
    int getRent(); // check to see if player can afford rent
};


#endif
