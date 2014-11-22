//
//  gameboard.h
//  
//
//  Created by Galen Wray on 2014-11-18.
//
//

#ifndef _gameboard_h
#define _gameboard_h

#include <iostream>
#include <string>
#include <map>
#include "square.h"
#include "textdisplay.h"

class Academic;
class Residence;
class Gym;

class Gameboard{
    Sqaure *theBoard[40]; // array of pointers to the 40 tiles on the board
    static GameBoard* instance; // one instance only of the board
    TextDisplay *td;
    
    //string contains the name of a block/type of building, and int contains the number of buildings of that type
    std::map<std::string, int> buildingCatalogue;
    
    // arrays of the specific block/type of building
    Academic *Arts1[2];
    Academic *Arts2[3];
    Academic *Eng[3];
    Academic *Health[3];
    Academic *Env[3]
    Academic *Sci1[3];
    Academic *Sci2[3];
    Academic *Math[2];
    Residence *Res[4];
    Gyms *Gym[2];
    
    GameBoard();
    
public:
    static void cleanup();
    static GameBoard* getInstance();
    Square* getSquare(int n);
    int getNumSiblings(std::string block);
    ~Gameboard();
    
    friend std::ostream &operator<<(std::ostream &out, const GameBoard & g);
    
};


#endif
