//
//  building.h
//  
//
//  Created by Galen Wray on 2014-11-18.
//
//

#ifndef _building_h
#define _building_h

#include "square.h"

class Player;

class Building : public Square{
protected:
    int numSiblings; // number of building of the same type/block
    int purchaseCost;
    bool owned;
    bool mortgaged;
    Player* owner;
    
public:
    Building();
    virtual bool isOwned() = 0;
    virtual bool isMortgaged() = 0;
    virtual bool mortgage() = 0;
    virtual bool unmortgage() = 0;
    virtual int getPurchaseCost() = 0; // need to check if can afford to buy the property
    virtual void purchase(Player *p) = 0; // buy property
    virtual void pay (Player *p) = 0; // pay tuition/rent
    ~Building();
};

#endif
