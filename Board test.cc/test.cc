//
//  main.cpp
//  main.cc
//
//  Created by Nisarg Patel on 2014-11-18.
//  Copyright (c) 2014 Nisarg Patel. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string *Display[56];
	string line;
	ifstream myfile("board.txt");
        //Display = string *[56];
        int i = 0;
		while (getline(myfile,line)) {
            string *tmp = new string (line);
            Display[i] = tmp;
            i++;
		}
    for (int j = 0; j < 56; j++) {
        cout << *(Display[j]) << endl;
    }
 }
