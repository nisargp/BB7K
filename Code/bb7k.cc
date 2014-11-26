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

void load(string file) {
    ifstream input(file.c_str());
    //create new gameboard
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
    while (TRUE) {
        string property;
        string owner;
        int improvements;
    }
}
