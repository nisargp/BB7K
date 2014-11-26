//
//  textdisplay.cc
//  
//
//  Created by Nisarg Patel on 2014-11-24.
//
//

#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include "textdisplay.h"

using namespace std;


TextDisplay::TextDisplay() {
    /*improvementLocation["EV1"] = "";
    improvementLocation["EV2"] = "";
    improvementLocation["EV3"] = "";
    improvementLocation["PHYS"] = "";
    improvementLocation["B1"] = "";
    improvementLocation["B2"] = "";
    improvementLocation["OPT"] = "";
    improvementLocation["EIT"] = "";
    improvementLocation["BMH"] = "";
    improvementLocation["ESC"] = "";
    improvementLocation["LHI"] = "";
    improvementLocation["C2"] = "";
    improvementLocation["CPH"] = "";
    improvementLocation["DWE"] = "";
    improvementLocation["MC"] = "";
    improvementLocation["RCH"] = "";
    improvementLocation["DC"] = "";
    improvementLocation["HH"] = "";
    improvementLocation["PAS"] = "";
    improvementLocation["ECH"] = "";
    improvementLocation["ML"] = "";
    improvementLocation["AL"] = "";*/
    
}

void TextDisplay::notify(string name, int numImprovement){
    if (numImprovement > 0) {
        for (int i = 0; i < numImprovement ; i++) {
            improvementLocation[name] += "I";
        }
    }
    else if(numImprovement < 0) {
        int length = improvementLocation[name].length();
        improvementLocation[name] = improvementLocation[name].substr (0, length - numImprovement);
    }
}


void TextDisplay::notify (string name, string current) {
    playerLocation[name] = current;
}

ostream &operator<<(ostream &out, TextDisplay &td) {
    map<string, string> playersatLocation;
    
    string ev1Imp = td.improvementLocation["EV1"];
    string ev2Imp = td.improvementLocation["EV2"];
    string ev3Imp = td.improvementLocation["EV3"];
    string physImp = td.improvementLocation["PHYS"];
    string b1Imp = td.improvementLocation["B1"];
    string b2Imp = td.improvementLocation["B2"];
    string optImp = td.improvementLocation["OPT"];
    string eitImp = td.improvementLocation["EIT"];
    string bmhImp = td.improvementLocation["BMH"];
    string escImp = td.improvementLocation["ESC"];
    string lhiImp = td.improvementLocation["LHI"];
    string c2Imp = td.improvementLocation["C2"];
    string cphImp = td.improvementLocation["CPH"];
    string dweImp = td.improvementLocation["DWE"];
    string mcImp = td.improvementLocation["MC"];
    string rchImp = td.improvementLocation["RCH"];
    string dcImp = td.improvementLocation["DC"];
    string hhImp = td.improvementLocation["HH"];
    string pasImp = td.improvementLocation["PAS"];
    string echImp = td.improvementLocation["ECH"];
    string mlImp = td.improvementLocation["ML"];
    string alImp = td.improvementLocation["AL"];
    
    for (map<string, string>::iterator i = td.playerLocation.begin(); i != td.playerLocation.end(); i++) {
        string location = i->second;
        playersatLocation[location] += i->first;
        
    }
    
    /*string nestPos, ev1Pos, needleTPos, ev2Pos, ev3Pos, v1Pos, physPos, b1Pos, cifPos, b2Pos, optPos, eitPos, bmhPos, escPos, slcLPos, slcRPos, lhiPos, c2Pos, uwpPos, revPos, cphPos, needleRPos, dwePos, mcPos, pacPos, coopPos, rchPos, dcPos, dcLPos, hhPos, pasPos, needleBPos, echPos, mkvPos, tuitionPos, mlPos, slcBPos, alPos, osapPos;*/
    
    string nestPos = playersatLocation["Goose Nesting"];
    string ev1Pos = playersatLocation["EV1"];
    string needleTPos = playersatLocation["NEEDLES HALL (T)"];
    string ev2Pos = playersatLocation["EV2"];
    string ev3Pos = playersatLocation["EV3"];
    string v1Pos = playersatLocation["V1"];
    string physPos = playersatLocation["PHYS"];
    string b1Pos = playersatLocation["B1"];
    string cifPos = playersatLocation["CIF"];
    string b2Pos = playersatLocation["B2"];
    string optPos = playersatLocation["OPT"];
    string eitPos = playersatLocation["EIT"];
    string bmhPos = playersatLocation["BMH"];
    string escPos = playersatLocation["ESC"];
    string slcLPos = playersatLocation["SLC (L)"];
    string slcRPos = playersatLocation["SLC (R)"];
    string lhiPos = playersatLocation["LHI"];
    string uwpPos = playersatLocation["UWP"];
    string revPos = playersatLocation["REV"];
    string c2Pos = playersatLocation["C2"];
    string cphPos = playersatLocation["CPH"];
    string needleRPos = playersatLocation["NEEDLES HALL (R)"];
    string dwePos = playersatLocation["DWE"];
    string mcPos = playersatLocation["MC"];
    string pacPos = playersatLocation["PAC"];
    string coopPos = playersatLocation["COOP FEE"];
    string rchPos = playersatLocation["RCH"];
    string dcPos = playersatLocation["DC"];
    string dcLPos = playersatLocation["DC Tims Line"];
    string hhPos = playersatLocation["HH"];
    string pasPos = playersatLocation["PAS"];
    string needleBPos = playersatLocation["NEEDLES HALL (B)"];
    string echPos = playersatLocation["ECH"];
    string mkvPos = playersatLocation["MKV"];
    string tuitionPos = playersatLocation["TUITION"];
    string mlPos = playersatLocation["ML"];
    string slcBPos = playersatLocation["SLC (B)"];
    string alPos = playersatLocation["AL"];
    string osapPos = playersatLocation["OSAP"];
    
    
    string divide = "-------|";
    string empty = "       |";
    string bottom = "_______|";
    string logotop = "_________________________________________";
    string logol3 = "|  ###   ###   #####  ###   ###   ###   |";
    string logol4 = "|  #  #  #  #     #  #   # #   # #   #  |";
    string logol5 = "|  ####  ####    #   #   # #   # #   #  |";
    string logol6 = "|  #   # #   #  #    #   # #   # #   #  |";
    string logol7 = "|  ####  ####  #      ###   ###   ###   |";
    string logol8 = "|_______________________________________|";
    
    for (int i = 0; i < 89; i++) out << '_';
    out << endl;
    out << '|' << left << setw(7) << "Goose" << '|' << setw(7) << ev1Imp << '|' << setw(7) << "NEEDLES" << '|' << setw(7) << ev2Imp << '|' << setw(7) << ev3Imp << '|';
    out << setw(7) << "V1" << '|' << setw(7) << physImp << '|' << setw(7) << b1Imp << '|' << setw(7) << "CIF" << '|' << setw(7) << b2Imp << '|' << setw(7) << "GO TO" << '|' << endl;
    
    out << '|' << setw(7) << "Nesting" << '|' << divide << setw(7) << "HALL" << '|' << divide << divide;
    out << setw(7) << " " << '|' << divide << divide << setw(7) << " " << '|' << divide << setw(7) << "TIMS" << '|' << endl;
    
    out << '|' << empty << setw(7) << "EV1" << '|' << empty << setw(7) << "EV2" << '|' << setw(7) << "EV3" << '|';
    out << empty << setw(7) << "PHYS" << '|' << setw(7) << "B1" << '|' << empty << setw(7) << "B2" << '|' << empty << endl;
    
    out << '|' << setw(7) << nestPos << '|' << setw(7) << ev1Pos << '|' << setw(7) << needleTPos << '|' << setw(7) << ev2Pos << '|' << setw(7) << ev3Pos << '|' << setw(7) << v1Pos << '|';
    out << setw(7) << physPos << '|' << setw(7) << b1Pos << '|' << setw(7) << cifPos << '|' << setw(7) << b2Pos << '|' << empty << endl;
    
    out << '|';
    for (int i = 0; i < 11; i++) out << bottom;
    out << endl;
    
    out << '|' << setw(7) << optImp << '|' << setw(71) << " " << '|' << setw(7) << eitImp << '|' << endl;
    out << '|' << divide << setw(71) << " " << '|' << divide << endl;
    out << '|' << "OPT    |" << setw(71) << " " << '|' << "EIT    |" << endl;
    out << '|' << setw(7) << optPos << '|' << setw(71) << " " << '|' << setw(7) << eitPos << '|' << endl;
    out << '|' << bottom << setw(71) << " " << '|' << bottom << endl;
    
    out << '|' << setw(7) << bmhImp << '|' << setw(71) << " " << '|' << setw(7) << escImp << '|' << endl;
    out << '|' << divide << setw(71) << " " << '|' << divide << endl;
    out << '|' << "BMH    |" << setw(71) << " " << '|' << "ESC    |" << endl;
    out << '|' << setw(7) << optPos << '|' << setw(71) << " " << '|' << setw(7) << eitPos << '|' << endl;
    out << '|' << bottom << setw(71) << " " << '|' << bottom << endl;
    
    out << '|' << "SLC    |" << setw(71) << " " << '|' << "SLC    |" << endl;
    out << '|' << empty << setw(71) << " " << '|' << empty << endl;
    out << '|' << empty << setw(71) << " " << '|' << empty << endl;
    out << '|' << setw(7) << slcLPos << '|' << setw(71) << " " << '|' << setw(7) << slcRPos << '|' << endl;
    out << '|' << bottom << setw(71) << " " << '|' << bottom << endl;
    
    out << '|' << setw(7) << lhiImp << '|' << setw(71) << " " << '|' << setw(7) << c2Imp << '|' << endl;
    out << '|' << divide << setw(71) << " " << '|' << divide << endl;
    out << '|' << "LHI    |" << setw(71) << " " << '|' << "C2     |" << endl;
    out << '|' << setw(7) << lhiPos << '|' << setw(15) << " " << logotop << setw(15) << " " << '|' << setw(7) << c2Pos << '|' << endl;
    out << '|' << bottom << setw(15) << " " << '|' << setw(39) << " " << '|' << setw(15) << " " << '|' << bottom << endl;
    
    out << '|' << "UWP    |" << setw(15) << " " << logol3 << setw(15) << " " << '|' << "REV    |" << endl;
    out << '|' << empty << setw(15) << " " << logol4 << setw(15) << " " << '|' << empty << endl;
    out << '|' << empty << setw(15) << " " << logol5 << setw(15) << " " << '|' << empty << endl;
    out << '|' << setw(7) << uwpPos << '|' << setw(15) << " " << logol6 << setw(15) << " " << '|' << setw(7) << revPos << '|' << endl;
    out << '|' << bottom << setw(15) << " " << logol7 << setw(15) << " " << '|' << bottom << endl;
    
    out << '|' << setw(7) << cphImp << '|' << setw(15) << " " << logol8 << setw(15) << " " << "|NEEDLES|" << endl;
    out << '|' << divide << setw(71) << " " << '|' << setw(7) << "HALL" << '|' << endl;
    out << '|' << setw(7) << "CPH" << '|' << setw(71) << " " << '|' << empty << endl;
    out << '|' << setw(7) << cphPos << '|' << setw(71) << " " << '|' << setw(7) << needleRPos << '|' << endl;
    out << '|' << bottom << setw(71) << " " << '|' << bottom << endl;
    
    out << '|' << setw(7) << dweImp << '|' << setw(71) << " " << '|' << setw(7) << mcImp << '|' << endl;
    out << '|' << divide << setw(71) << " " << '|' << divide << endl;
    out << '|' << "DWE    |" << setw(71) << " " << '|' << "MC     |" << endl;
    out << '|' << setw(7) << dwePos << '|' << setw(71) << " " << '|' << setw(7) << mcPos << '|' << endl;
    out << '|' << bottom << setw(71) << " " << '|' << bottom << endl;
    
    out << '|' << "PAC    |" << setw(71) << " " << '|' << "COOP   |" << endl;
    out << '|' << empty << setw(71) << " " << '|' << setw(7) << "FEE" << '|' << endl;
    out << '|' << empty << setw(71) << " " << '|' << empty << endl;
    out << '|' << setw(7) << pacPos << '|' << setw(71) << " " << '|' << setw(7) << coopPos << '|' << endl;
    out << '|' << bottom << setw(71) << " " << '|' << bottom << endl;

    out << '|' << setw(7) << rchImp << '|' << setw(71) << " " << '|' << setw(7) << dcImp << '|' << endl;
    out << '|' << divide << setw(71) << " " << '|' << divide << endl;
    out << '|' << "RCH    |" << setw(71) << " " << '|' << "DC     |" << endl;
    out << '|' << setw(7) << rchPos << '|' << setw(71) << " " << '|' << setw(7) << dcPos << '|' << endl;
    out << '|' << bottom;
    for (int i = 0; i < 71; i++) out << '_';
    out << '|' << bottom << endl;
    
    out << '|' << "DC Tims|" << setw(7) << hhImp << '|' << setw(7) << pasImp << '|' << "NEEDLES|";
    out << setw(7) << echImp << '|' << setw(7) << "MKV" << "|TUITION|" << setw(7) << mlImp << '|';
    out << setw(7) << "SLC" << '|' << setw(7) << alImp << "|COLLECT|" << endl;
    
    out << '|' << setw(7) << "Line" << '|' << divide << divide << setw(7) << "HALL" << '|' << divide;
    out << empty << empty << divide << empty << divide << setw(7) << "OSAP" << '|' << endl;
    
    out << '|' << empty << setw(7) << "HH" << '|' << setw(7) << "PAS" << '|' << empty << setw(7) << "ECH" << '|';
    out << empty << empty << setw(7) << "ML" << '|' << empty << setw(7) << "AL" << '|' << empty << endl;
    
    out << '|' << setw(7) << dcLPos << '|' << setw(7) << hhPos << '|' << setw(7) << pasPos << '|' << setw(7) << needleBPos << '|' << setw(7) << echPos;
    out << '|' << setw(7) << mkvPos << '|' << setw(7) << tuitionPos << '|' << setw(7) << mlPos << '|' << setw(7) << slcBPos << '|' << setw(7) << alPos << '|' << setw(7) << osapPos << '|' << endl;
    
    out << '|';
    for (int i = 0; i < 11; i++) out << bottom;
    out << endl;
    
    return out;
}