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
class Player;

class Gameboard{
    // initialize regularly
    Square *theBoard[40]; // array of pointers to the 40 tiles on the board
    static Gameboard* instance; // one instance only of the board
    TextDisplay *td;
    Player* p[6];
    int numPlayers;
    
    //string contains the name of a block/type of building, and int contains the number of buildings of that type
    std::map<std::string, int> buildingCatalogue;
    
    // arrays of the specific block/type of building
    //Academic *Arts1[2];
    //Academic *Arts2[3];
    //Academic *Eng[3];
    //Academic *Health[3];
    //Academic *Env[3]
    //Academic *Sci1[3];
    //Academic *Sci2[3];
    //Academic *Math[2];
    //Residence *Res[4];
    //Gyms *Gym[2];
    
    Gameboard();
    
public:
    // Get methods
    static Gameboard* getInstance();
    Square* getSquare(int n);
    Square* getSquare(std::string name);
    int getNumSiblings(std::string block);
    Player* getPlayer(std::string name);
<<<<<<< Updated upstream
    Player* getPlayer(int position);
=======
    int getNumPlayers();
>>>>>>> Stashed changes
    
    // Change values
    void addPlayer(Player *p);
    void removePlayer(Player *p);
    
    // Freeing memory
    static void cleanup();
    ~Gameboard();
    
    friend std::ostream &operator<<(std::ostream &out, const Gameboard & g);
    
};


#endif
