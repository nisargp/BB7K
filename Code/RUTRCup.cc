//
//  RUTRCup.cc
//  
//
//  Created by Galen Wray on 2014-11-23.
//
//

#include "RUTRCup.h"

int RUTRCup::cupCount = 0;

RUTRCup::RUTRCup(){ RUTRCup::cupCount++; }

RUTRCup* RUTRCup::getCup(){
    if (RUTRCup::cupCount == 4) return 0;
    else {
        RUTRCup * cup = new RUTRCup;
        return cup;
    }
}

RUTRCup::~RUTRCup(){ RUTRCup::cupCount--; }