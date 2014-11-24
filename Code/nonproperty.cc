//
//  nonproperty.cc
//  
//
//  Created by Galen Wray on 2014-11-20.
//
//

#include "nonproperty.h"
#include <cstdlib>
#include <iostream>

using namespace std;

NonProperty::NonProperty(string name, int sqrNum): Square(name, sqrNum) {
    g = Gameboard::getInstance();
}

void NonProperty::land(Player *p){
    cout<<"You have landed on: " << getName() << "." << endl;
    
    
    if (getName() == "Collect OSAP"){
        // should we only have give out money when they pass to avoid giving money out twice?
    }
    
    
    else if (getName() == "DC Tims Line"){
        // nothing if you land
    }
    
    
    else if (getName() == "Go to Tims"){
        p->DCTimsLine = true;
        p->currLocation = g->getSquare(10);
        cout << "You have been sent to the DC Tims Line." << endl;
    }
    
    
    else if (getName() == "Goose Nesting"){
        cout << "You were attacked by a flock of nesting geese." << endl;
    }
    
    
    else if (getName() == "Tuition"){
        int payTotalWorth = 0.1 * p->getTotalWorth();
        
        if (300 >= payTotalWorth){
            p->trade(300, 0);
            cout << "You have paid $300 in tuition." << endl;
        } else {
            if (p->getMoney - payTotalWorth < 0) {
                p->payOut = payTotalWorth;
                p->bankruptcy = true;
                cout << "You owe $" << payTotalWorth << " but you only have $" << p->getMoney << "." << endl;
                return;
            }
            p->trade(payTotalWorth, 0);
            cout << "You have paid $" << payTotalWorth << " in tuition." << endl;
        }
    }
    
    
    else if (getName() == "Coop Fee"){
        if (p->getMoney - 150 < 0) {
            p->payOut = 150;
            p->bankruptcy = true;
            return;
            cout << "You owe $150 but you only have $" << p->getMoney << "." << endl;
        }
        p->trade(150, 0);
        cout << "You have paid a $150 coop fee." << endl;
    }
    
    
    else if (getName() == "SLC"){
        int randNum = rand % 100 + 1;
        
        if (randNum == 1){
            RUTRCup * cup = RUTRCup::getCup();
            if(!cup){
                p->addCup(cup);
                cout << "You have received a winning Roll Up the Rim Cup." << endl;
            }
            else {
                cout << "There are no winning Roll Up the Rim Cups remaining." << endl;
            }
        }
        else { // SLC probabilities
            randNum = rand % 48 + 1;
            
            if (randNum >= 1 && randNum <= 6){
                // move back 3
                cout << "Move back 3." << endl;
                int newSquare = p->currLocation->getSquareNum - 3;
                if (newSquare < 0){
                    newSquare = 40 - newSquare;
                }
                p->currLocation = g->getSquare(newSquare);
                p->currLocation->land(p);
                p->notify();
            }
            
            else if (randNum >= 7 && randNum <= 14){
                // move back 2
                cout << "Move back 2." << endl;
                int newSquare = p->currLocation->getSquareNum - 2;
                if (newSquare < 0){
                    newSquare = 40 - newSquare;
                }
                p->currLocation = g->getSquare(newSquare);
                p->currLocation->land(p);
                p->notify();
            }
            
            else if (randNum >= 15 && randNum <= 22){
                // move back 1
                cout << "Move back 1." << endl;
                int newSquare = p->currLocation->getSquareNum - 1;
                if (newSquare < 0){
                    newSquare = 40 - newSquare;
                }
                p->currLocation = g->getSquare(newSquare);
                p->currLocation->land(p);
                p->notify();
            }
            
            else if (randNum >= 23 && randNum <= 28){
                // move forward 1
                cout << "Move forward 1." << endl;
                int newSquare = p->currLocation->getSquareNum + 1;
                if (newSquare > 39){
                    newSquare -= 40;
                    cout << "You have passed Collect OSAP and collected $200." << endl;
                    p->trade(0,200);
                }
                p->currLocation = g->getSquare(newSquare);
                p->currLocation->land(p);
                p->notify();
            }
            
            else if (randNum >= 29 && randNum <= 36){
                // move forward 2
                cout << "Move forward 2." << endl;
                int newSquare = p->currLocation->getSquareNum + 2;
                if (newSquare > 39){
                    newSquare -= 40;
                    cout << "You have passed Collect OSAP and collected $200." << endl;
                    p->trade(0,200);
                }
                p->currLocation = g->getSquare(newSquare);
                p->currLocation->land(p);
                p->notify();
            }
            
            else if (randNum >= 37 && randNum <= 44){
                // move forward 3
                cout << "Move forward 3." << endl;
                int newSquare = p->currLocation->getSquareNum + 3;
                if (newSquare > 39){
                    newSquare -= 40;
                    cout << "You have passed Collect OSAP and collected $200." << endl;
                    p->trade(0,200);
                }
                p->currLocation = g->getSquare(newSquare);
                p->currLocation->land(p);
                p->notify();
            }
            
            else if (randNum == 45 || randNum == 46){
                p->DCTimsLine = true;
                p->currLocation = g->getSquare(10);
                cout << "You have been sent to the DC Tims Line." << endl;
                p->notify();
            }
            
            else if (randNum == 47 || randNum == 48){
                p->currLocation = g->getSquare(0);
                cout << "You have been sent to Collect OSAP and collected $200." << endl;
                p->trade(0,200);
                p->notify();
            }
        }
    }
    
    
    else if (getName() == "Needles Hall"){
        int randNum = rand % 100 + 1;
        
        if (randNum == 1){
            RUTRCup * cup = RUTRCup::getCup();
            if(!cup){
                p->addCup(cup);
                cout << "You have received a winning Roll Up the Rim Cup." << endl;
            }
            else {
                cout << "There are no winning Roll Up the Rim Cups remaining." << endl;
            }
        }
        else { // Needles Hall probabilites
            randNum = rand % 18 + 1;
            
            if (randNum == 1){
                if (p->getMoney - 200 < 0) {
                    p->payOut = 200;
                    p->bankruptcy = true;
                    return;
                    cout << "You owe $200 but you only have $" << p->getMoney << "." << endl;
                }
                // lose 200$
                p->trade(200,0);
                cout << "You have lost $200." << endl;
            }
            else if (randNum == 2 || randNum == 3){
                if (p->getMoney - 100 < 0) {
                    p->payOut = 100;
                    p->bankruptcy = true;
                    return;
                    cout << "You owe $100 but you only have $" << p->getMoney << "." << endl;
                }
                // lose 100$
                p->trade(100,0);
                cout << "You have lost $100." << endl;
            }
            else if (randNum >= 4 && randNum <= 6){
                if (p->getMoney - 50 < 0) {
                    p->payOut = 50;
                    p->bankruptcy = true;
                    return;
                    cout << "You owe $50 but you only have $" << p->getMoney << "." << endl;
                }
                // lose 50$
                p->trade(50,0);
                cout << "You have lost $50." << endl;
            }
            else if (randNum >= 7 && randNum <= 12){
                // gain 25$
                p->trade(0,25);
                cout << "You have received $25." << endl;
            }
            else if (randNum >= 13 && randNum <= 15){
                // gain 50$
                p->trade(0,50);
                cout << "You have received $50." << endl;
            }
            else if (randNum == 16 || randNum == 17){
                // gain 100$
                p->trade(0,100);
                cout << "You have received $100." << endl;
            }
            else if (randNum == 18){
                // gain 200$
                p->trade(0,200);
                cout << "You have received $200." << endl;
            }
        }
    }

}