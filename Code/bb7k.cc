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

int roll(int die1 = 0, int die2 = 0) {
    int move;
    if (die1 == 0 && die2 == 0) {
        die1 = rand() % 6 + 1;
        die2 = rand() % 6 + 1;
    }
    cout << "Die 1: " << die1 << " Die 2: " << die2 << endl;
    move = die1 + die2;
    return move;
}

void gameplay(Gameboard &gb, bool rolltest) {
    string command;
    Player *currPlayer;
    int player;
    
    while (cin >> command) {
        if (cmd == "roll") {
            int die1 = 0;
            int die2 = 0;
            if (rolltest) {
                cin >> die1 >> die2;
            }
            roll(die1, die2);
            roll = true;
        }
        else if (cmd == "next") {
            
            if (roll) {
                roll = false;
                player++;
                if (player > 6) player -= 6;
                currPlayer = gb.getPlayer(player);
            }
            else cout << "Current Player has not rolled yet!" << endl;
        }
        else if (cmd == "trade") {
            string name;
        }
        else if (cmd == "improve") {
            
        }
        else if (cmd == "mortgage") {
            
        }
        else if (cmd == "unmortgage") {
            
        }
        else if (cmd == "bankrupt") {
            
        }
        else if (cmd == "assets") {
            assets(currPlayer);
        }
        else if (cmd == "save") {
            string filename;
            cin >> filename;
            save(gb, filename);
        }
    }
    
}
void assets(Player *p) {
    cout << "Print assets of Player" << endl;
}
void save(Gameboard &gb, string filename) {
    cout << "Saving file" << endl;
}

int main(int args, char *argv[]) {
    srand((unsigned)time(0));
    bool rolltest = false;
    Gameboard *gb = NULL; //new Gameboard();
    addplayers(*gb);
    gameplay(gb, rolltest);
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