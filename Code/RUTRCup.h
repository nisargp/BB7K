//
//  RUTRCup.h
//  
//
//  Created by Galen Wray on 2014-11-18.
//
//

#ifndef _RUTRCup_h
#define _RUTRCup_h

class RUTRCup{
    static int cupCount;
    // constructor checks the number of cup counts
    RUTRCup();
    
public:
    RUTRCup * getCup();
    // destructor subtracts one from the number of cups
    ~RUTRCup();
    
};

#endif
