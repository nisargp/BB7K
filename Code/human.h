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
    Human();
    void roll();
    void notify();
    void trade(int give, int receive);
    void trade(std::string give, int receive);
    void trade(int give, std::string receive);
    void trade(std::string give, std::string receive);
    void isBankrupt();
    void declareBankruptcy();
    ~Human();
};


#endif
