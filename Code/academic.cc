//
//  academic.cc
//  
//
//  Created by Galen Wray on 2014-11-20.
//
//

#include "academic.h"
#include <iostream>

using namespace std;

Academic::Academic(string name, int sqrNum,int numSiblings, int purchaseCost, bool owned, bool mortgaged, Player* owner, std::string block, bool blockOwned, int improvementCost, int improvementLevel, int *tuition, TextDisplay *td)
        : Building(name, sqrNum, numSiblings, purchaseCost, owned, mortgaged, owner), block(block), blockOwned(blockOwned), improvementCost(improvementCost), improvementLevel(improvementLevel), td(td){
            for (int i = 0; i < 6; i++){
                this->tuition[i] = tuition[i];
            }
}


void Academic::notifyTextDisplay(int changeImprovements){
    td->notify(name, changeImprovements);
}

void Academic::mortgage(){
    if(improvementLevel != 0) {
        cout<< "You must sell all improvements before mortgaging the property." << endl;
        cout<< "Would you still like to mortgage the building? (Y/N)" << endl;
        
        string s;
        cin>>s;
        if (s == N || s == n) return;
        
        while(improvementLevel != 0){
            improve(-1);
        }
    }
    
    owner->trade(0, purchaseCost/2);
    mortgaged = true;
    cout << name << " has been mortgaged." << endl;
}

int Academic::getTuition(){ return tuition[improvementLevel]; }


void Academic::pay(Player *p){
    if (!mortgaged){
        if(improvementLevel == 0 && blockOwned){
            p->trade(tuition[improvementLevel] * 2, 0);
            owner->trade(0, tuition[improvementLevel] * 2);
        }
        else {
            p->trade(tuition[improvementLevel], 0);
            owner->trade(0, tuition[improvementLevel]);
        }

    }
    else {
        cout << "The building is mortgaged. No tuition is required." << endl;
    }
}

void Academic::improve(int numImprovments){
    if (numImprovments == 1){
        if (blockOwned){
            if (improvementLevel < 5){
                owner->trade(improvementCost, 0);
                numImprovments++;
                notifyTextDisplay(numImprovments);
            }
            else cout << "You already have a maximum number of improvements on your building." << endl;
        }
        else cout<< "You must own the entire block to get improvements." << endl;
        
    }
    else if (numImprovments == -1){
        if (numImprovments != 0){
            owner->trade(0, improvementCost/2);
            numImprovments--;
            notifyTextDisplay(numImprovments);
        }
        else cout << "You don't have any improvements on this building to remove." << endl;
    }
    
}



void Academic::purchase(Player* p){
    if (!owned){
        owner->trade(purchaseCost, 0);
        
        owned = true;
        owner = p;
        // need to check if it exists first (do the same for the other properties)
        owner->buildingCatalogue[block]++;
        if (p->buildingCatalogue[block] == numSiblings) blockOwned == true;
    }
    
    
}
