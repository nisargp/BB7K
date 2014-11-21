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
public:
    std::string name;
    Square(name);
    virtual ~Square() = 0;
};
#endif
