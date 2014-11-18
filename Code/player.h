//
//  player.h
//  
//
//  Created by Galen Wray on 2014-11-18.
//
//

#ifndef _player_h
#define _player_h


#include <string>
#include <map>
class Square;
class RUTRCup;


class Player{
    std::string name;
    char piece;
    int money;
    
    Square* currPosition;
    int position;
    
    int numAssets;
    string property[28];
    
    RUTRCup * cup [4];
    int numCups;
    bool DCTimsLine;
    int payOut; //amount of money owed for rent/tutition
    bool bankruptcy; // update if player can decalre bankruptcy

public:
    Player();
    std::map<std::string, int> buildingCatalogue;
    
    virtual void roll() = 0; // update the position by adding the roll, sets currPosition to the square of the gameboard at that position
    virtual void notify() = 0;
    virtual void trade(int give, int receive) = 0; // function to perform the actual trade
    virtual void trade(std::string give, int receive) = 0;
    virtual void trade(int give, std::string receive) = 0;
    virtual void trade(std::string give, std::string receive) = 0;
    virtual void isBankrupt() = 0;
    virtual void declareBankruptcy() = 0;
    virtual ~Player();
};



#endif
