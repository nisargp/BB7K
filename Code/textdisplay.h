//
//  textdisplay.h
//  
//
//  Created by Galen Wray on 2014-11-18.
//
//

#ifndef _textdisplay_h
#define _textdisplay_h

#include <map>
#include <iostream>
#include <string>

class TextDisplay{
protected:
    std::map<std::string, std::string> playerLocation; // first string: player name, second string: location
    std::map<std::string, std::string> improvementLocation; // first string: building name, second string: location
    
public:
    TextDisplay();
    void notify(std::string name, int numImprovement); // changes improvements on text display
    void notify (std::string name, std::string current); // changes the location of the player on the text display
    
    friend std::ostream &operator<<(std::ostream &out, TextDisplay & td);
    
};

#endif
