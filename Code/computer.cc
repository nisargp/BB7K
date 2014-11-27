//
//  computer.cc
//  
//
//  Created by Galen Wray on 2014-11-24.
//
//


#include "player.h"
#include "square.h"
#include "gameboard.h"
#include "building.h"
#include "academic.h"
#include "residence.h"
#include "gym.h"
#include "RUTRCup.h"
#include "textdisplay.h"
#include "human.h"
#include "computer.h"


using namespace std;

Computer::Computer(string name, char piece, int money, Square* currPosition, int numAssets, Building ** property, RUTRCup ** cup, int numCups, bool DCTimsLine, int numTurnsDC, int payOut, bool bankruptcy, TextDisplay* td)
: Player(name, piece, money, currPosition, numAssets, property, cup, numCups, DCTimsLine, numTurnsDC, payOut, bankruptcy, td){}


void Computer::buyProperty(Building * b){
    if (money > b->getPurchaseCost()) b->purchase(this);
    else cout << name << " has decided not to purchase " << b->getName() << endl;
}


void Computer::payPlayer(Building * b){
    payOut = b->getPay();
    if (money > payOut) b->pay(this);
    else declareBankruptcy(b->getOwner());
}

void Computer::pay(){
    if (money > payOut) {
        trade(payOut, 0);
        cout << "You have lost $" << payOut << "." << endl;
    }
    else declareBankruptcy();
}


bool Computer::accept(int give, int receive){
    if (receive >= give) return true;
    return false;
}
bool Computer::accept(int give, string receive){
    Building * rec = dynamic_cast<Building*>(g->getSquare(receive));
    if (give <= rec->getPurchaseCost()) return true;
    return false;
}
bool Computer::accept(string give, string receive){
    Building * rec = dynamic_cast<Building*>(g->getSquare(receive));
    Building * giv = dynamic_cast<Building*>(g->getSquare(give));
    if (giv->getPurchaseCost() <= rec->getPurchaseCost()) return true;
    return false;
}

bool Computer::accept(string give, int receive){
    Building * giv = dynamic_cast<Building*>(g->getSquare(give));
    if (receive >= giv->getPurchaseCost()) return true;
    return false;
}

void Computer::unmortgageTorB(Building *b){
    if (money >= b->getPurchaseCost()/2 * 1.1) {
        b->unmortgage();
    }
    else {
        trade(b->getPurchaseCost() * .1, 0);
    }
    
}

void Computer::improvements(Building *b){
    while (money >= b->getImprovementCost() && b->getImprovementLevel() < 5){
        b->improve(1);
    }
}

