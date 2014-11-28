//
//  computer.h
//  
//
//  Created by Galen Wray on 2014-11-18.
//
//

#ifndef _computer_h
#define _computer_h

#include <string>
#include "player.h"

class Computer: public Player{
public:
    Computer(std::string name, char piece, TextDisplay* td, int money = 1500, Square* currPosition = 0, int numAssets = 0, Building ** property = 0, RUTRCup ** cup = 0, int numCups = 0, bool DCTimsLine = false, int numTurnsDC = 0,int payOut = 0, bool bankruptcy = false);

    void buyProperty(Building * b); // calls purchase if it wants to buy the property
    void payPlayer(Building * b); // calls pay if the player has enough funds, otherwise they must declare bankruptcy
    void pay();
    bool accept(int give, int receive); // returns true if it is a good trade, and it wants to trade, false otherwise
    bool accept(int give, std::string receive);
    bool accept(std::string give, int receive);
    bool accept(std::string give, std::string receive);
    
    void unmortgageTorB(Building *b);
    void improvements(Building *b);
    
    // still needs to be able to buy/sell?
};



#endif
