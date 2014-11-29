//
//  square.cc
//  
//
//  Created by Galen Wray on 2014-11-20.
//
//

#include "square.h"

using namespace std;

// Constructor
Square::Square(string name, int sqrNum): name(name), sqrNum(sqrNum){}

// Returns the number in the array for the gameboard
int Square::getSquareNum(){ return sqrNum; }

// Returns the name of the square
string Square::getName(){ return name; }

//Destructor
Square::~Square(){}