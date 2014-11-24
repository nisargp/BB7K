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

class Square;
class RUTRCup;


class Player{
protected:
    std::string name;
    char piece;
    int money;
    
    Square* currPosition;
    
    int numAssets;
    Square* property[28];
    
    RUTRCup * cup [4];
    int numCups;
    
    Gameboard * g; 

public:
    std::map<std::string, int> buildingCatalogue;
    
    int payOut; //amount of money owed for rent/tutition (check if == 0 after every turn)
    
    bool bankruptcy; // update if player can decalre bankruptcy
    
    bool DCTimsLine;
    int numTurnsDC;
    
    
    Player(std::string name, char piece, int money, Square* currPosition, int numAssets, Square ** property, RUTRCUP ** cup, int numCups, bool DCTimsLine, int numTurnsDC, int payOut, bool bankruptcy);
    
    
    // Notifies text display to move piece around the board
    void notify();
    
    
    // Get Methods
    int getTotalWorth(); // gets your total worth (including your savings, printed prices of all buildings you own and costs of each improvement)
    std::string getName();
    int getMoney();
    
    
    
    // Add methods
    int addCup(RUTRCUP * cup);
    
    
    // Gameplay
    void roll(int move); // update the position by adding the roll, sets currPosition to the square of the gameboard at that position
    void trade(int give, int receive); // function to perform the actual trade
    void trade(std::string give, int receive);
    void trade(int give, std::string receive);
    void trade(std::string give, std::string receive);
    void declareBankruptcy(Player *p);
    void declareBankruptcy();
    
    // Pure Virtual Methods
    virtual void buyProperty() = 0; // calls purchase if it wants to buy the property
    virtual void pay() = 0; // calls pay if the player has enough funds, otherwise they must declare bankruptcy
    
    
    virtual ~Player();
    
    
    friend void NonProperty::land(Player* p);
};



#endif
