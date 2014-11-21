//
//  nonproperty.cc
//  
//
//  Created by Galen Wray on 2014-11-20.
//
//

#include "nonproperty.h"
#include <cstdlib>

using namespace std;

NonProperty::NonProperty(string name): Square(name) {}

void NonProperty::land(Player *p){
    if (name == "Collect OSAP"){
        // should we only have give out money when they pass to avoid giving money out twice?
    }
    else if (name == "DC Tims Line"){
        // nothing if you land
    }
    else if (name == "Go to Tims"){
        p->DCTimsLine = true;
        // p-> currLocation = ...
    }
    else if (name == "Goose Nesting"){
        cout << "You were attacked by a flock of nesting geese." << endl;
    }
    else if (name == "Tuition"){
        // have a field for the total value of all assets of a player?
    }
    else if (name == "Coop Fee"){
        p->trade(150, 0);
    }
    else if (name == "SLC"){
        // ...
    }
    else if (name == "Needles Hall"){
        //...
    }
    // roll up the rim cup**
}