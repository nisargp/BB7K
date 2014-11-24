//
//  human.h
//  
//
//  Created by Galen Wray on 2014-11-18.
//
//

#ifndef _human_h
#define _human_h

#include <string>
#include "player.h"

class Human: public Player{
public:
    Human(std::string name, char piece, int money, Square* currPosition, int numAssets, Square ** property, RUTRCUP ** cup, int numCups, bool DCTimsLine, int numTurnsDC, int payOut, bool bankruptcy);
    void buyProperty(); // calls purchase if it wants to buy the property
    void pay(); // calls pay if the player has enough funds, otherwise they must declare bankruptcy
};


#endif
