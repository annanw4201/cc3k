//
//  MoveControl.cpp
//  test
//
//  Created by Wang Annan on 2016-11-26.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "MoveControl.h"
using namespace std;

string MoveControl(string &input) {
    if (input == "no") {
        return "North";
    }
    else if (input == "ea") {
        return "East";
    }
    else if (input == "so") {
        return "South";
    }
    else if (input == "we") {
        return "West";
    }
    else if (input == "ne") {
        return "NorthEast";
    }
    else if (input == "nw") {
        return "NorthWest";
    }
    else if (input == "se") {
        return "SouthEast";
    }
    else if (input == "sw") {
        return "SouthWest";
    }
    else if (input == "f") {
        return "EnemyFreeze";
    }
    else if (input == "EnableWASD") {
        return "EnableWASD";
    }
    else {
        return "NoCommand";
    }
}

string MoveControl(char &input) {
    if (input == 'w') {
        return "North";
    }
    else if (input == 'd') {
        return "East";
    }
    else if (input == 's') {
        return "South";
    }
    else if (input == 'a') {
        return "West";
    }/*
    else if (input == "ne") {
        return "NorthEast";
    }
    else if (input == "nw") {
        return "NorthWest";
    }
    else if (input == "se") {
        return "SouthEast";
    }
    else if (input == "sw") {
        return "SouthWest";
    }
    else if (input == 'f') {
        return "EnemyFreeze";
    }
    else if (input == "EnableWASD") {
        return "EnableWASD";
    }*/
    else {
        return "NoCommand";
    }
}

bool ValidDirection (string &input) {
    if (input == "North" || input == "East" || input == "South" || input == "West" ||
        input == "NorthEast" || input == "NorthWest" || input == "SouthEast" || input == "SouthWest") {
        return true;
    }
    else {
        return false;
    }
}

void useNcurses() {
    initscr();
    noecho();
    nonl();
    cbreak();
    if(has_colors()) {
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        init_pair(2, COLOR_YELLOW, COLOR_BLACK);
        init_pair(3, COLOR_MAGENTA, COLOR_CYAN);
        init_pair(4, COLOR_BLACK, COLOR_MAGENTA);
        init_pair(5, COLOR_MAGENTA, COLOR_WHITE);
        init_pair(6, COLOR_MAGENTA, COLOR_YELLOW);
    }
    timeout(-1);
}
