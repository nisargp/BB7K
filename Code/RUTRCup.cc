//
//  RUTRCup.cc
//  
//
//  Created by Galen Wray on 2014-11-23.
//
//

#include "RUTRCup.h"

using namespace std;

RUTRCup::RUTRCup(){ cupCount++; }

RUTRCup* RUTRCup::getCup(){
    if (cupCount == 4) return NULL;
    else return new RUTRCup; // is this possible?
}

RUTRCup::RUTRCup(){ cupCount--; }