//
//  nonproperty.h
//  
//
//  Created by Galen Wray on 2014-11-18.
//
//

#ifndef _nonproperty_h
#define _nonproperty_h

#include "square.h"
class Player;

class NonProperty: public Square{
    Gameboard *g;
public:
    NonProperty(std::string name, int sqrNum);
    void land(Player *p);
};




#endif
