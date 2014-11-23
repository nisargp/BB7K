//
//  player.cc
//  
//
//  Created by Galen Wray on 2014-11-23.
//
//

#include "player.h"


Player::Player(std::string name, char piece, int money, Square* currPosition, int position, int numAssets, string * property, RUTRCUP ** cup, int numCups, bool DCTimsLine, int payOut, bool bankruptcy)
: name(name), piece (piece), currPosition(currPosition), position(position), numAssets(numAssets), numCups(numCups), DCTimsLine(DCTimsLine), payOut(payOut), bankruptcy(bankruptcy){
    for (int i = 0; i < numAssets; i++){
        this->property[i] = property[i];
    }
    for (int i = 0; i < numCups; i++){
        this->cup[i] = cup[i];
    }
}




/*

 class Player{
 std::string name;
 char piece;
 int money;
 
 Square* currPosition;
 int position;
 
 int numAssets;
 string property[28];
 
 RUTRCup * cup [4];
 int numCups;
 bool DCTimsLine;
 int payOut; //amount of money owed for rent/tutition
 bool bankruptcy; // update if player can decalre bankruptcy
 
 public:
 std::map<std::string, int> buildingCatalogue;
 
 virtual void roll() = 0; // update the position by adding the roll, sets currPosition to the square of the gameboard at that position
 virtual void notify() = 0;
 virtual void trade(int give, int receive) = 0; // function to perform the actual trade
 virtual void trade(std::string give, int receive) = 0;
 virtual void trade(int give, std::string receive) = 0;
 virtual void trade(std::string give, std::string receive) = 0;
 virtual void isBankrupt() = 0;
 virtual void declareBankruptcy() = 0;
 virtual ~Player();
 
 virtual int getTotalWorth() = 0; // gets your total worth (including your savings, printed prices of all buildings you own and costs of each improvement)
 virtual int addCup(RUTRCUP * cup);
 
 friend void NonProperty::land(Player* p);
 };


*/