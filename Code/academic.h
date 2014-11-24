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
    bool blockOwned;
    int improvementCost;
    int improvementLevel;
    int tuition[6];
    TextDisplay* td;
    
    // Notify (Observer Pattern)
    void notifyTextDisplay(int changeImprovements);
    
public:
    Academic(std::string name, int sqrNum, int numSiblings, int purchaseCost, bool owned, bool mortgaged, Player* owner, std::string block, bool blockOwned, int improvementCost, int improvementLevel, int *tuition, TextDisplay *td);
    
    // Get private values
    int getTuition(); // check to see if player can afford tuition
    int getImprovementCost();
    int getImprovementLevel();
    
    // Change private values
    void mortgage();
    void purchase(Player* p);
    void pay(Player *p);
    void improve(int numImprovments); // 1 for improve, -1 for removing an improvement

};

#endif
