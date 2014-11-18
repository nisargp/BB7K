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
#inlcude "player.h"

class Computer: public Player{
public:
    Computer();
    void roll();
    void notify();
    void trade(int give, int receive);
    void trade(std::string give, int receive);
    void trade(int give, std::string receive);
    void trade(std::string give, std::string receive);
    void isBankrupt();
    void declareBankruptcy();
    bool accept(int give, int receive); // returns true if it is a good trade, and it wants to trade, false otherwise
    bool accept(int give, std::string receive);
    bool accept(std::string give, std::string receive);
    bool accept(std::string give, std::string receive);
    int getMoney(); // returns the amount of money that the computer player has
    ~Computer();
};



#endif
