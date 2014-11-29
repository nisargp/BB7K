//
//  gameboard.cc
//  
//
//  Created by Galen Wray on 2014-11-25.
//
//

#include "gameboard.h"
#include "square.h"
#include "academic.h"
#include "residence.h"
#include "gym.h"
#include "nonproperty.h"
#include "player.h"

using namespace std;

Gameboard *Gameboard::instance = 0;


Gameboard::Gameboard(){
    // Text Display
    td = new TextDisplay();
    
    //Player Array
    for (int i = 0; i < 6; i++){
        p[i] = NULL;
    }
    numPlayers = 0;
    
    // buildingCatalogue map
    buildingCatalogue["Arts1"] = 2;
    buildingCatalogue["Arts2"] = 3;
    buildingCatalogue["Eng"] = 3;
    buildingCatalogue["Health"] = 3;
    buildingCatalogue["Env"] = 3;
    buildingCatalogue["Sci1"] = 3;
    buildingCatalogue["Sci2"] = 3;
    buildingCatalogue["Math"] = 2;
    buildingCatalogue["Res"] = 4;
    buildingCatalogue["Gym"] = 2;
    
    // theBoard Initialization
    // NonProperty (name || square number)
    // Academic (name || square number || number of siblings (in block)|| purchase cost || block name ||  improvement cost || tuition array|| text display)
    // Residence(name || square number || number of siblings (all residences) || purchase cost || block name || rent array)
    // Gym (name || square number || number of siblings (all gyms) || purchase cost || block name)
    int t[6]; // Tuition Array
    int r[4]; // Rent Array
    r[0] = 25;
    r[1] = 50;
    r[2] = 100;
    r[3] = 200;
    theBoard[0] = new NonProperty("COLLECT OSAP", 0);
    t[0] = 2;
    t[1] = 10;
    t[2] = 30;
    t[3] = 90;
    t[4] = 160;
    t[5] = 250;
    theBoard[1] = new Academic("AL", 1, 2, 40, "Arts1", 50, t, td);
    theBoard[2] = new NonProperty("SLC (B)", 2);
    t[0] = 4;
    t[1] = 20;
    t[2] = 60;
    t[3] = 180;
    t[4] = 320;
    t[5] = 450;
    theBoard[3] = new Academic("ML", 3, 2, 60, "Arts1", 50, t, td);
    theBoard[4] = new NonProperty("TUITION", 4);
    theBoard[5] = new Residence("MKV", 5, 4, 200, "Res", r);
    t[0] = 6;
    t[1] = 30;
    t[2] = 90;
    t[3] = 270;
    t[4] = 400;
    t[5] = 550;
    theBoard[6] = new Academic("ECH", 6, 3, 100, "Arts2", 50, t, td);
    theBoard[7] = new NonProperty("NEEDLES HALL (B)", 7);
    theBoard[8] = new Academic("PAS", 8, 3, 100, "Arts2", 50, t, td);
    t[0] = 8;
    t[1] = 40;
    t[2] = 100;
    t[3] = 300;
    t[4] = 450;
    t[5] = 600;
    theBoard[9] = new Academic("HH", 9, 3, 120, "Arts2", 50, t, td);
    theBoard[10] = new NonProperty("DC Tims Line", 10);
    t[0] = 10;
    t[1] = 50;
    t[2] = 150;
    t[3] = 450;
    t[4] = 625;
    t[5] = 750;
    theBoard[11] = new Academic("RCH", 11, 3, 140, "Eng", 100, t, td);
    theBoard[12] = new Gym("PAC", 12, 2, 150, "Gym");
    theBoard[13] = new Academic("DWE", 13, 3, 140, "Eng", 100, t, td);
    t[0] = 12;
    t[1] = 60;
    t[2] = 180;
    t[3] = 500;
    t[4] = 700;
    t[5] = 900;
    theBoard[14] = new Academic("CPH", 14, 3, 160, "Eng", 100, t, td);
    theBoard[15] = new Residence("UWP", 15, 4, 200, "Res", r);
    t[0] = 14;
    t[1] = 70;
    t[2] = 200;
    t[3] = 550;
    t[4] = 750;
    t[5] = 950;
    theBoard[16] = new Academic("LHI", 16, 3, 180, "Health", 100, t, td);
    theBoard[17] = new NonProperty("SLC (L)", 17);
    theBoard[18] = new Academic("BMH", 18, 3, 180, "Health", 100, t, td);
    t[0] = 16;
    t[1] = 80;
    t[2] = 220;
    t[3] = 600;
    t[4] = 800;
    t[5] = 1000;
    theBoard[19] = new Academic("OPT", 19, 3, 200, "Health", 100, t, td);
    theBoard[20] = new NonProperty("Goose Nesting", 20);
    t[0] = 18;
    t[1] = 90;
    t[2] = 250;
    t[3] = 700;
    t[4] = 875;
    t[5] = 1050;
    theBoard[21] = new Academic("EV1", 21, 3, 220, "Env", 150, t, td);
    theBoard[22] = new NonProperty("NEEDLES HALL (T)", 22);
    theBoard[23] = new Academic("EV2", 23, 3, 220, "Env", 150, t, td);
    t[0] = 20;
    t[1] = 100;
    t[2] = 300;
    t[3] = 750;
    t[4] = 925;
    t[5] = 1100;
    theBoard[24] = new Academic("EV3", 24, 3, 240, "Env", 150, t, td);
    theBoard[25] = new Residence("V1", 25, 4, 200, "Res", r);
    t[0] = 22;
    t[1] = 110;
    t[2] = 330;
    t[3] = 800;
    t[4] = 975;
    t[5] = 1150;
    theBoard[26] = new Academic("PHYS", 26, 3, 260, "Sci1", 150, t, td);
    theBoard[27] = new Academic("B1", 27, 3, 260, "Sci1", 150, t, td);
    theBoard[28] = new Gym("CIF", 28, 2, 150, "Gym");
    t[0] = 24;
    t[1] = 120;
    t[2] = 360;
    t[3] = 850;
    t[4] = 1025;
    t[5] = 1200;
    theBoard[29] = new Academic("B2", 29, 3, 280, "Sci1", 150, t, td);
    theBoard[30] = new NonProperty("GO TO TIMS", 30);
    t[0] = 26;
    t[1] = 130;
    t[2] = 390;
    t[3] = 900;
    t[4] = 1100;
    t[5] = 1275;
    theBoard[31] = new Academic("EIT", 31, 3, 300, "Sci2", 200, t, td);
    theBoard[32] = new Academic("ESC", 32, 3, 300, "Sci2", 200, t, td);
    theBoard[33] = new NonProperty("SLC (R)", 33);
    t[0] = 28;
    t[1] = 150;
    t[2] = 450;
    t[3] = 1000;
    t[4] = 1200;
    t[5] = 1400;
    theBoard[34] = new Academic("C2", 34, 3, 320, "Sci2", 200, t, td);
    theBoard[35] = new Residence("REV", 35, 4, 200, "Res", r);
    theBoard[36] = new NonProperty("NEEDLES HALL (R)", 36);
    t[0] = 35;
    t[1] = 175;
    t[2] = 500;
    t[3] = 1100;
    t[4] = 1300;
    t[5] = 1500;
    theBoard[37] = new Academic("MC", 37, 2, 350, "Math", 200, t, td);
    theBoard[38] = new NonProperty("COOP FEE", 38);
    t[0] = 50;
    t[1] = 205;
    t[2] = 600;
    t[3] = 1400;
    t[4] = 1700;
    t[5] = 2000;
    theBoard[39] = new Academic("DC", 39, 2, 400, "Math", 200, t, td);
}



// Get Methods
Gameboard* Gameboard::getInstance(){
    if (!instance){
        instance = new Gameboard;
        atexit(cleanup);
    }
    return instance;
}


Square* Gameboard::getSquare(int n){ return theBoard[n]; }


Square* Gameboard::getSquare(string name){
    for (int i = 0; i < 40; i++){
        if (theBoard[i]->getName() == name) return theBoard[i];
    }
    return NULL;
}


int Gameboard::getNumSiblings(string block){ return buildingCatalogue[block]; }


Player* Gameboard::getPlayer(string name){
    for  (int i = 0; i < numPlayers; i++){
        if (p[i]->getName() == name) return p[i];
    }
    return NULL;
}

int Gameboard::getNumPlayers() {
    return numPlayers;
}

Player* Gameboard::getPlayer(int position) {
    return this->p[num - 1];
}


// Change values
void Gameboard::addPlayer(Player *p){
    this->p[numPlayers] = p;
    numPlayers++;
}

void Gameboard::removePlayer(Player *p){
    bool found = false;
    for (int i = 0; i < numPlayers; i++){
        if (!found && p == this->p[i]) {
            found = true;
            numPlayers--;
        }
        if (found){
            if (i != numPlayers - 1) this->p[i] = this->p[i+1];
            else this->p[i] = NULL;
        }
    }
    delete p;
}





// Freeing memory
void Gameboard::cleanup(){
    delete instance;
}


Gameboard::~Gameboard(){
    delete td;
    for (int i = 0; i < 40; i++){
        delete theBoard[i];
    }
    for (int i = 0; i < numPlayers; i++){
        delete p[i];
    }
    
}


ostream &operator<<(ostream &out, const Gameboard & g){
    out << *(g.td);
    return out;
}

