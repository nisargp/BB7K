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
    cout << "Please enter number of players: ";
    int numPlayers;
    cin >> numPlayers;
}


void gameplay(Gameboard &gb) {
    
}

int main(int args, char **argv) {
    bool rolltest = false;
    Gameboard *gb = new Gameboard();
    addplayers(&gb);
    if (args > 1) {
        for (int i = 1; i < args; i++) {
            if (argv[i] == "-testing") {
                rolltest = true;
            }
            else if (arg[i] == "-load") {
                i++;
                string filename = argv[i];
                delete gb;
                gb = new Gameboard();
                load(filename, &gb);
            }
        }
    }
    
    
}