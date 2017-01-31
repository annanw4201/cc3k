//
//  MoveControl.hpp
//  test
//
//  Created by Wang Annan on 2016-11-26.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef MoveControl_hpp
#define MoveControl_hpp

#include <string>
#include <ncurses.h>

std::string MoveControl(std::string &input);
std::string MoveControl(char &);
bool ValidDirection (std::string &input);

void useNcurses();
#endif /* MoveControl_hpp */
