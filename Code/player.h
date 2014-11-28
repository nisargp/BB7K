//
//  player.h
//  
//
//  Created by Galen Wray on 2014-11-18.
//
//

#ifndef _player_h
#define _player_h


#include <string>
#include <map>
#include "nonproperty.h"

class Square;
class RUTRCup;
class Building;
class TextDisplay;

class Player{
protected:
    std::string name;
    char piece;
    int money;
    
    Square* currPosition;
    
    int numAssets;
    Building* property[28];
    
    RUTRCup * cup [4];
    int numCups;
    
    int payOut; //amount of money owed for rent/tutition (check if == 0 after every turn)
    
    bool bankruptcy; // update if player can decalre bankruptcy
    
    bool DCTimsLine;
    int numTurnsDC;
    
    Gameboard * g;
    TextDisplay *td;

public:
    std::map<std::string, int> buildingCatalogue;
    

    
    
    Player(std::string name, char piece, TextDisplay* td, int money = 1500, Square* currPosition = 0, int numAssets = 0, Building ** property = 0, RUTRCup ** cup = 0, int numCups = 0, bool DCTimsLine = false, int numTurnsDC = 0,int payOut = 0, bool bankruptcy = false);
    
    
    // Notifies text display to move piece around the board
    void notify();
    
    
    // Get Methods
    int getTotalWorth(); // gets your total worth (including your savings, printed prices of all buildings you own and costs of each improvement)
    std::string getName();
    int getMoney();
    
    
    
    // Add methods
    void addCup(RUTRCup * cup);
    
    
    // Gameplay
    void roll(int move); // update the position by adding the roll, sets currPosition to the square of the gameboard at that position
    void trade(int give, int receive); // function to perform the actual trade
    void trade(std::string give, int receive);
    void trade(int give, std::string receive);
    void trade(std::string give, std::string receive);
    void declareBankruptcy(Player *p);
    void declareBankruptcy();
    void printAssets();
    
    // Pure Virtual Methods
    virtual void buyProperty(Building * b) = 0; // calls purchase if it wants to buy the property
    virtual void payPlayer(Building * b) = 0; // calls pay if the player has enough funds, otherwise they must declare bankruptcy
    virtual void pay() = 0; // calls pay if the player has enough funds, otherwise they must declare bankruptcy
    virtual bool accept(int give, int receive) = 0; // returns true if it is a good trade, and it wants to trade, false otherwise
    virtual bool accept(int give, std::string receive) = 0;
    virtual bool accept(std::string give, int receive) = 0;
    virtual bool accept(std::string give, std::string receive) = 0;
    virtual void unmortgageTorB(Building *b) = 0; // Deals with unmortgaging for trading or bankruptcy (for the receiving player)
    virtual void improvements(Building *b) = 0;
    
    
    virtual ~Player();
    
    
    friend void NonProperty::land(Player* p);
    friend void helperGetMoney(Player *player, std::string s, bool tuition, bool play); // tuition boolean is for whether or not the player is paying tuition (and so can't display assets)
};



#endif
