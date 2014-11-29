//
//  human.cc
//  
//
//  Created by Galen Wray on 2014-11-23.
//
//

#include "human.h"
#include "player.h"
#include "square.h"
#include "gameboard.h"
#include "building.h"
#include "academic.h"
#include "residence.h"
#include "gym.h"
#include "RUTRCup.h"
#include "textdisplay.h"
#include <iostream>

using namespace std;

Human::Human(string name, char piece, TextDisplay* td, int money, Square* currPosition, int numAssets, Building ** property, RUTRCup ** cup, int numCups, bool DCTimsLine, int numTurnsDC, int payOut, bool bankruptcy)
: Player(name, piece, td, money, currPosition, numAssets, property, cup, numCups, DCTimsLine, numTurnsDC, payOut, bankruptcy){}


void helperGetMoney(Player* player, string s, bool tuition){
    
    // Mortgage to get more money
    if(s == "mortgage"){
        cin >> s;
        for (int i = 0; i < player->numAssets; i++){
            if (player->property[i]->getName() == s) {
                player->property[i]->mortgage();
                break;
            }
        }
    }
    else if (s == "assets"){
        if (!tuition) player->printAssets();
        else cout << "Error. You cannot see your assets when figuring out how to pay tuition." << endl;
    }
    // Remove improvements to get more money
    else if (s == "improve"){
        cin >> s;
        string s1;
        cin >> s1;
        if (s1 != "sell") {
            cout << "Error. You can only sell improvements at this time." << endl;
        }
        else {
            for (int i = 0; i < player->numAssets; i++){
                if (player->property[i]->getName() == s) {
                    player->property[i]->improve(-1);
                    break;
                }
            }
        }
    }
    
    // Trade other player to get more money
    else if (s == "trade"){
        cin>> s;
        Player* p = player->g->getPlayer(s); // get a pointer to the player to play with
        int gi, ri; // give, receive (integers)
        string gs, rs; // give, receive (strings)
        
        if (cin >> gi){
            if (cin >> ri){
                //
                // Give - integer, Receive - integer trade
                //
                cout << player->getName() << " has offered a trade of $" << gi << "for $" << ri << " to " << p->getName() << endl;
                
                // Check to see if player that is being offered wants to trade
                if(p->accept(gi, ri)){
                    player->trade(gi, ri);
                    p->trade(ri, gi);
                    cout << player->getName() << " has traded " << gi << "for $" << ri << " with " << p->getName() << endl;
                }
                else cout << "Your trade has been denied." << endl;
                
            } else {
                //
                // Give - integer, Receive - string trade
                //
                cin.clear(); // clears fail bit
                cin >> rs;
                Building *receive = dynamic_cast<Building*>(player->g->getSquare(rs)); // finds pointer to appropriate building
                
                bool canTrade = true; // no other buildings on a block have improvements
                
                // Checks to see if owner has entire set (of academic buildings), and thus could have added improvements
                if (dynamic_cast<Academic*>(receive) && p->buildingCatalogue[receive->getBlock()] == player->g->getNumSiblings(rs)){
                    
                    // Goes through list of player's assets to check if any of them on the same block have improvements
                    for (int i = 0; i < player->numAssets; i++){
                        
                        if (p->property[i]->getBlock() == receive->getBlock()){ // same block
                            if (p->property[i]->getImprovementLevel() != 0){
                                cout << "You cannot trade for this property. " << p->getName() << " must sell improvements on the entire block (specifically  " << player->property[i]->getName() << ") before trading." << endl;
                                canTrade = false;
                                break;
                            }
                        }
                    }
                } // end of check for improvements
                
                // If you can still trade:
                if (canTrade){
                    cout << player->getName() << " has offered a trade of $" << gi << "for " << rs << " to " << p->getName() << endl;
                    if(p->accept(gi, rs)){
                        player->trade(gi, rs);
                        p->trade(rs, gi);
                        cout << player->getName() << " has traded " << gi << "for $" << rs << " with " << p->getName() << endl;
                    }
                    else cout << "Your trade has been denied." << endl;
                    
                }
            } // end of else
        } else {
            
            // Give - string
            cin.clear(); // clears fail bit
            cin >> gs;
            Building *give = dynamic_cast<Building*> (player->g->getSquare(gs)); // finds pointer to appropriate building
            
            bool canTrade = true;// no other buildings on a block have improvements
            
            // Checks to see if owner has entire set (of academic buildings), and thus could have added improvements
            if (dynamic_cast<Academic*>(give) && give->getOwner()->buildingCatalogue[give->getBlock()] == player->g->getNumSiblings(gs)){
                
                // Goes through list of player's assets to check if any of them on the same block have improvements
                for (int i = 0; i < player->numAssets; i++){
                    
                    if (player->property[i]->getBlock() == give->getBlock()){ // same block
                        if (player->property[i]->getImprovementLevel() != 0){
                        cout << "You must sell improvements on the entire block (specifically  " << player->property[i]->getName() << ") before trading." << endl;
                            cin.ignore(); // ignore the next value (ie. the receive value) - doesn't matter, can't do the trade
                        canTrade = false;
                        break;
                        }
                    }
                }
            }// end of check for improvements
            
            // If you can still trade:
            if (canTrade){
                
                // Checks value of receive
                if (cin >> ri){
                    
                    //
                    // Give - string, Receive - integer trade
                    //
                    cout << player->getName() << " has offered a trade of " << gs << "for $" << ri << " to " << p->getName() << endl;
                    if(p->accept(gs, ri)){
                        player->trade(gs, ri);
                        p->trade(ri, gs);
                        cout << player->getName() << " has traded " << gs << "for $" << ri << " with " << p->getName() << endl;
                    }
                    else cout << "Your trade has been denied." << endl;
                }
                else {
                    
                    //
                    // Give - string, Receive - string trade
                    //
                    
                    cin.clear(); // clears fail bit
                    
                    cin >> rs;
                    Building *receive = dynamic_cast<Building*>(player->g->getSquare(rs)); // finds pointer to appropriate building
                    
                    bool canTrade = true;// no other buildings on a block have improvements
                    
                    // Checks to see if owner has entire set (of academic buildings), and thus could have added improvements
                    if (dynamic_cast<Academic*>(receive) && receive->getOwner()->buildingCatalogue[receive->getBlock()] == player->g->getNumSiblings(rs)){
                        
                        // Goes through list of player's assets to check if any of them on the same block have improvements
                        for (int i = 0; i < player->numAssets; i++){
                            
                            if (player->property[i]->getBlock() == receive->getBlock()){ // same block
                                if (player->property[i]->getImprovementLevel() != 0){
                                    cout << "You cannot trade for this property. " << receive->getOwner() << " must sell improvements on the entire block (specifically  " << player->property[i]->getName() << ") before trading." << endl;
                                    canTrade = false;
                                    break;
                                }
                            }
                            
                        }
                    }
                
                    if (canTrade){
                        cout << player->getName() << " has offered a trade of $" << gs << "for " << rs << " to " << p->getName() << endl;
                        if(p->accept(gs, rs)){
                            player->trade(gs, rs);
                                p->trade(rs, gs);
                            cout << player->getName() << " has traded " << gs << "for $" << rs << " with " << p->getName() << endl;
                    }
                    else cout << "Your trade has been denied." << endl;
                    
                    }
                }
            }
        }
    }
}

void Human::buyProperty(Building * b){
    // Ask if they want to purchase
    cout << "Would you like to purchase " << b->getName() << " for $" << b->getPurchaseCost() << "? (Y/N)" << endl;
    string s;
    cin>>s;
    
    // If they want to purchase the property
    if (s == "Y"){
        while (b->getPurchaseCost() > money){
            cout << "You don't have enough money to purchase " << b->getName() << ". You need $" << b->getPurchaseCost() - money << ". What would you like to do? (Enter 'C' to cancel, or you can mortgage properties, remove improvements, or trade assets to get the necessary money. Enter 'assets' to view your list of properties.)" << endl;
            
            cin>>s;
            
            if (s == "C") {
                cout << name << " has decided not to purchase " << b->getName() << endl;
                return;
            }
            
            helperGetMoney(this, s, false);
            
        }
        b->purchase(this);
    }
    else cout << name << " has decided not to purchase " << b->getName() << endl;
}


void Human::payPlayer(Building * b){
    payOut = b->getPay();
    while (payOut > money){
        bankruptcy = true;
        cout << "You owe $" << payOut << " but you only have $" << money << "." << endl;
        cout<< "What would you like to do? (Declare bankruptcy, mortgage, remove improvements or trade assets.)" << endl;
        string s;
        cin >> s;
        if (s == "bankrupt") {
            declareBankruptcy(b->getOwner());
            return;
        }
        helperGetMoney(this, s, true);
    }
    
    b->pay(this);
    
}



void Human::pay(){

    while (payOut > money){
        bankruptcy = true;
        cout << "You owe $" << payOut << " but you only have $" << money << "." << endl;
        cout<< "What would you like to do? (Declare bankruptcy, print your assets, mortgage, remove improvements or trade assets.)" << endl;
        string s;
        cin >> s;
        if (s == "bankrupt") {
            declareBankruptcy();
            return;
        }
        helperGetMoney(this, s, false);
    }
    
    trade(payOut, 0);
    
    cout<< "You have paid $" << payOut<< "." << endl;
}



bool Human::accept(int give, int receive){
    cout << name << ", would you like to accept the trade? (accept/reject)" << endl;
    string s;
    cin >> s;
    
    if (s == "accept") return true;
    return false;
}

bool Human::accept(int give, string receive){
    cout << name << ", would you like to accept the trade? (accept/reject)" << endl;
    string s;
    cin >> s;
    
    if (s == "accept") return true;
    return false;
}

bool Human::accept(string give, int receive){
    cout << name << ", would you like to accept the trade? (accept/reject)" << endl;
    string s;
    cin >> s;
    
    if (s == "accept") return true;
    return false;
}

bool Human::accept(string give, string receive){
    cout << name << ", would you like to accept the trade? (accept/reject)" << endl;
    string s;
    cin >> s;
    
    if (s == "accept") return true;
    return false;
}



void Human::unmortgageTorB(Building *b){
    string s;
    cout << name<< ", " <<b->getName() << " is mortgaged. Would you like to unmortgage it? (Y/N)" << endl;
    cin >> s;
    
    if (s == "Y"){
        b->unmortgage();
    }
    else {
        trade(b->getPurchaseCost() * .1, 0);
    }
}


void Human::improvements(Building *b){
    cout << "You now own the entire " << b->getBlock() << " block, so you can add improvements." << endl;
}


