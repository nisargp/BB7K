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
    int sqrNum;
public:
    std::string name;
    Square(std::string name, int sqrNum);
    int getSquareNum();
    virtual ~Square() = 0;
};
#endif
