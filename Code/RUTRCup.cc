//
//  RUTRCup.cc
//  
//
//  Created by Galen Wray on 2014-11-23.
//
//

#include "RUTRCup.h"

RUTRCup::RUTRCup(){ cupCount++; }

RUTRCup* RUTRCup::getCup(){
    if (cupCount == 4) return 0;
    else {
        RUTRCup * cup = new RUTRCup;
        return cup;
    }
}

RUTRCup::~RUTRCup(){ cupCount--; }