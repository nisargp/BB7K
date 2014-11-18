//
//  academic.h
//  
//
//  Created by Galen Wray on 2014-11-18.
//
//

#ifndef _academic_h
#define _academic_h

#include <string>
#include "building.h"

class TextDisplay;
class Player;

class Academic: public Building {
    std::string block;
    bool blockOwned;
    int improvementCost;
    int improvementLevel;
    int tuition[6];
    TextDisplay* td;
    
    void notifyTextDisplay();
    
public:
    Academic();
    bool isOwned();
    bool isMortgaged();
    void mortgage();
    void unmortgage();
    int getPurchaseCost();
    void purchase(Player* p);
    void pay(Player *p);
    void improve(int numImprovments); // 1 for improve, -1 for removing an improvement
    void getTuition(); // check to see if player can afford tuition
    ~Academic();
};

#endif
