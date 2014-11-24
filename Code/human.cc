//
//  human.cc
//  
//
//  Created by Galen Wray on 2014-11-23.
//
//

#include "human.h"
#include <iostream>

using namespace std;

Human::Human(string name, char piece, int money, Square* currPosition, int numAssets, Square ** property, RUTRCUP ** cup, int numCups, bool DCTimsLine, int numTurnsDC, int payOut, bool bankruptcy)
: Player(name, piece, money, currPosition, numAssets, property, cup, numCups, DCTimsLine, numTurnsDC, payOut, bankruptcy){}



void buyProperty(){
    cout << "Would you like to purchase " << p->currPosition->getName() << " for $" << p->currPosition->getPurchaseCost << "? (Y/N)" << endl;
    string s;
    cin>>s;
    if (s == "Y"){
        while (p->currPosition->getPurchaseCost() > money){
            cout << "You don't have enough money to purchase " << p->currPosition->getName() << ". You need $" << p->currPosition->getPurchaseCost() - money << ". What would you like to do? (Enter 'C' to cancel, or you can mortgage properties/remove improvements/trade assets.)" << endl;
            cin>>s;
            
            if (s == "C") return;
            if (s == "mortgage"){
                cin >> s;
                for (int i = 0; i < numAssets; i++){
                    if (property[i]->getName == s) {
                        property[i]->mortgage();
                        break;
                    }
                }
            }
            else if (s == "improve"){
                cin >> s;
                string s1;
                cin >> s1;
                if (s1 != "sell") {
                    cout << "Error. You can only sell improvements." << endl;
                }
                else {
                    for (int i = 0; i < numAssets; i++){
                        if (property[i]->getName == s) {
                            property[i]->improve(-1);
                            break;
                        }
                    }
                }
            }
            else if (s == "trade"){
                // what to put here??
            }
        }
        
        p->currPosition->purchase(p);
    }
}


void pay(){
    // finish
}