//
//  square.h
//  
//
//  Created by Galen Wray on 2014-11-18.
//
//

#ifndef _square_h
#define _square_h

#include <string>

class Square{
    int sqrNum; // number in the array for the gameboard
    std::string name;
    
public:
    Square(std::string name, int sqrNum);
    int getSquareNum();
    std::string getName(); // note: this is a new addition - may cause errors if I called 'name' directly and didn't change it
    virtual void land(Player *p) = 0;
};
#endif
