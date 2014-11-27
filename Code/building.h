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
#include <string>

class Player;
class Gameboard;

class Building : public Square{
private:
    int purchaseCost;
    
protected:
    int numSiblings; // number of building of the same type/block (used in purchase)
    bool mortgaged;
    std::string block;// block name for academic buildings, or residence/gym
    bool owned;
    Player* owner;
    
public:
    Building(std::string name, int sqrNum, int numSiblings, int purchaseCost, std::string block);
    
    // Gets values of protected fields
    int getPurchaseCost();
    std::string getBlock();
    bool isOwned();
    bool isMortgaged();
    Player * getOwner();
    
    // Change values of protected fields
    void unmortgage();
    virtual void changeOwner(Player *p, bool owned = true); // When assets are traded
    
    // Method for each time you land on a square (check to purchase)
    void land(Player *p);
    
    // Pure virtual methods
    virtual void mortgage() = 0; // needs to be in subclasses to sell improvements before mortgaging
    virtual void purchase(Player *p) = 0; // buy property
    virtual void pay (Player *p) = 0; // pay tuition/rent
    virtual int getPay() = 0; // gets tuition/rent/usage fee that needs to be paid
    
    // Only for academic
    virtual void improve(int numImprovments) = 0;
    virtual int getImprovementCost() = 0;
    virtual int getImprovementLevel() = 0;

};

#endif
