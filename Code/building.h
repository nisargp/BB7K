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
#include "string.h"

class Player;
class Gameboard;

class Building : public Square{
protected:
    int numSiblings; // number of building of the same type/block
    int purchaseCost;
    bool owned;
    bool mortgaged;
    Player* owner;
    
public:
    Building(std::string name, int sqrNum, int numSiblings, int purchaseCost, bool owned, bool mortgaged, Player* owner);
    virtual bool isOwned();
    virtual bool isMortgaged();
    virtual void mortgage() = 0;
    virtual void unmortgage();
    virtual int getPurchaseCost(); // need to check if can afford to buy the property
    virtual void purchase(Player *p) = 0; // buy property
    virtual void pay (Player *p) = 0; // pay tuition/rent
};

#endif
