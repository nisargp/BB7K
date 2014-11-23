//
//  square.cc
//  
//
//  Created by Galen Wray on 2014-11-20.
//
//

#include "square.h"

using namespace std;

Square::Square(string name, int sqrNum): name(name), sqrNum(sqrNum){}

Square::~Square(){}

in Square::getSquareNum(){ return sqrNum; }
