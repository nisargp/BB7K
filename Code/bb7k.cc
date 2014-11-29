//
//  bb7k.cc
//  
//
//  Created by Nisarg Patel on 2014-11-25.
//
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "gameboard.h"
#include "player.h"
#include "square.h"
#include "computer.h"
#include "building.h"
#include "academic.h"
#include "residence.h"
#include "gym.h"
#include "RUTRCup.h"
#include "textdisplay.h"

using namespace std;

void load(string file, Gameboard &gb) {
    ifstream input(file.c_str());
    int numPlayers;
    input >> numPlayers;
    for (int i = 0; i < numPlayers; i++) {
        string name;
        int money;
        int position;
        input >> name >> money >> position;
        //create new player with money and position
        if (position == 10) {
            int injail;
            input >> injail;
            if (injail == 1) {
                int tries;
                input >> tries;
                //do something
            }
        }
    }
    string property;
    while (input >> property) {
        string property;
        string owner;
        int improvements;
        input >> owner >> improvements;
        // change owner of property
        // add improvements
    }
}

void addplayers(Gameboard &gb) {
    int numPlayers;
    string typePlayer;
    string name;
    char piece;
    char pieces[8];
    pieces[0] = 'G';
    pieces[1] = 'B';
    pieces[2] = 'D';
    pieces[3] = 'P';
    pieces[4] = 'S';
    pieces[5] = '$';
    pieces[6] = 'L';
    pieces[7] = 'T';

    cout << "Please enter number of players: ";
    cin >> numPlayers;
    for (int i = 0; i < numPlayers; i++) {
        cout << "Please enter name of Player " << (i + 1) << ": ";
        cin >> name;
        cout << "Please enter type of player (human or computer): ";
        cin >> typePlayer;
        int max = 8 - i;
        if (typePlayer == "human") {
            cout << "Please select a piece from the following (";
            for (int k = 0; k < max; k++) {
                cout << pieces[k] << " ";
            }
            cout << "): ";
            cin >> piece;
        }
        else {
            piece = pieces[0];
        }
        for (int l = 0, j = 0; l < max; l++, j++) {
            if (piece == pieces[l]) {
                j++;
            }
            pieces[l] = pieces[j];
        }
        pieces[max - 1] = '\0';
        if (typePlayer == "human") {
            cout << "Human added" << endl;
            //Human *newPlayer = new Human(name, piece, gb.td);
            //gb.addplayer(newPlayer);
        }
        else {
            cout << "Computer added" << endl;
            //Computer *newPlayer = new Computer(name, piece, gb.td);
            //gb.addplayer(newPlayer);
        }
    }
}

int roll(int die1 = 0, int die2 = 0, bool &doubles) {
    int move;
    if (die1 == 0 && die2 == 0) {
        die1 = rand() % 6 + 1;
        die2 = rand() % 6 + 1;
    }
    if (die1 == die2) doubles = true;
    cout << "Die 1: " << die1 << " Die 2: " << die2 << endl;
    move = die1 + die2;
    return move;
}


void trade(Player* player){
    string s;
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

void improve(Player* player) {
    string s;
    cin >> s;
    string s1;
    cin >> s1;
    
    int i;
    
    if (s1 == "sell") i = -1;
    else i = 1;
        
    for (int i = 0; i < player->numAssets; i++){
        if (player->property[i]->getName() == s) {
            player->property[i]->improve(i);
            break;
        }
    }
}

void save(Gameboard &gb, string filename) {
    cout << "Saving file" << endl;
}

void gameplay(Gameboard &gb, bool rolltest) {
    bool doubles = false;
    int numDoubles = 0;
    bool roll = false;
    string cmd;
    Player *currPlayer = NULL;
    int player;
    
    while (cin >> cmd) {
        if (cmd == "roll") {
            int die1 = 0;
            int die2 = 0;
            int move = 0;
            if (rolltest) {
                cin >> die1 >> die2;
            }
<<<<<<< Updated upstream
            roll(die1, die2);
            roll = true;
        }
        else if (cmd == "next") {
            
            if (roll) {
                roll = false;
                player++;
                if (player > 6) player -= 6;
=======
            move = roll(die1, die2, doubles);
            currPlayer->roll(move);
            while (numDoubles < 3 && doubles) {
                numDoubles++;
                doubles = false;
                move = roll(die1, die2, doubles);
                currPlayer->roll(move);
            }
            roll = true;
        }
        else if (cmd == "next") {
            if (roll) {
                roll = false;
                player++;
                int numPlayers = gb.getNumPlayers();
                if (player > numPlayers) player -= numPlayers;
>>>>>>> Stashed changes
                currPlayer = gb.getPlayer(player);
            }
            else cout << "Current Player has not rolled yet!" << endl;
        }
        else if (cmd == "trade") {
            trade(currPlayer);
        }
        else if (cmd == "improve") {
            improve(currPlayer);
        }
        else if (cmd == "mortgage") {
            string s;
            cin >> s;
            for (int i = 0; i < currPlayer->numAssets; i++){
                if (currPlayer->property[i]->getName() == s) {
                    currPlayer->property[i]->mortgage();
                    break;
                }
            }
        }
        else if (cmd == "unmortgage") {
            string s;
            cin >> s;
            for (int i = 0; i < currPlayer->numAssets; i++){
                if (currPlayer->property[i]->getName() == s) {
                    currPlayer->property[i]->unmortgage();
                    break;
                }
            }
        }
        else if (cmd == "bankrupt") {
            // should we do anything here?
            cout << "You can't declare bankruptcy at this time." << endl;
        }
        else if (cmd == "assets") {
            currPlayer->printAssets();
        }
        else if (cmd == "save") {
            string filename;
            cin >> filename;
            save(gb, filename);
        }
    }
    
}


int main(int args, char *argv[]) {
    srand((unsigned)time(0));
    bool rolltest = false;
    Gameboard *gb = NULL; //new Gameboard();
    addplayers(*gb);
    gameplay(*gb, rolltest);
    if (args > 1) {
        for (int i = 1; i < args; i++) {
            if (strcmp(argv[i], "-testing") == 0) {
                rolltest = true;
            }
            else if (strcmp(argv[i], "-load") == 0) {
                i++;
                string filename = argv[i];
                //delete gb;
                //gb = new Gameboard();
                //load(filename, *gb);
            }
        }
    }
    cout << "END of main" << endl;
}