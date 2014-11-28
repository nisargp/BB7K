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
#include "gameboard.h"
#include

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
        cout << endl << "Please enter name of Player " << (i + 1) << ": "
        cin >> name;
        cout << endl << "Please enter type of player (human or computer): ";
        cin >> typePlayer;
        if (typePlayer == "human") {
            cout << endl << "Please select a piece from the following (";
            int max = 8 - i;
            for (int k = 0; k < max; k++) {
                cout << pieces[k] << " ";
            }
            cout << "): ";
            cin >> piece;
        }
        else {
            piece = pieces[0];
        }
        for (int l = 0, j = 0; l < 8; l++, j++) {
            if (piece == pieces[i]) {
                j++;
            }
            pieces[l] = pieces[j];
        }
        pieces[8] = '\0';
        if (typePlayer == "human") {
            cout << "Human added" << endl;
           // Human newPlayer = new Human(name, piece, gb.td);
        }
        else {
            cout << "Human added" << endl;
            //Computer newPlayer = new Computer(name, piece, gb.td);
        }
    }
}


void gameplay(Gameboard &gb) {
    
}

int main(int args, char **argv) {
    bool rolltest = false;
    Gameboard *gb = NULL; //new Gameboard();
    addplayers(&gb);
    if (args > 1) {
        for (int i = 1; i < args; i++) {
            if (argv[i] == "-testing") {
                rolltest = true;
            }
            else if (argv[i] == "-load") {
                i++;
                string filename = argv[i];
                delete gb;
                gb = new Gameboard();
                load(filename, &gb);
            }
        }
    }
    cout << "END of main";
}