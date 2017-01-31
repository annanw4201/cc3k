//
//  textDisplay.cpp
//  test
//
//  Created by Wang Annan on 2016-11-20.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "TextDisplay.h"
#include "../character/player/player.h"
#include <iomanip>

using namespace std;

// TextDisplay constructor
TextDisplay::TextDisplay(const int &row, const int &col):
row{row}, col{col}, pc{nullptr}, Action{""} {
    theDisplay.resize(row, vector <string> (col, " "));
}

// TextDisplay destructor
TextDisplay::~TextDisplay() {
}

// set the player to be binded to the TextDisplay
void TextDisplay::setPc(const player *pc) {
    this->pc = pc;
}

// get the player
const player * TextDisplay::getPc() const{
    return pc;
}

// TextDisplay notify to change the position to be the char type
void TextDisplay::notify(const int &row, const int &col, const string &type) {
    theDisplay[row][col] = type;
}

// TextDisplay to get the Type according to row and col
string TextDisplay::getType(const int &row, const int &col) const{
    return theDisplay[row][col];
}

// get the row of TextDisplay
int TextDisplay::getRow() const {
    return row;
}

// get the col of TextDisplay
int TextDisplay::getCol() const {
    return col;
}

// update the Action of the player
void TextDisplay::updateAct(const string &mssg) {
    Action = Action + mssg;
}

// get the Action of TextDisplay
string TextDisplay::getAct() const{
    return Action;
}

// reset the Action information
void TextDisplay::resetAct() {
    Action = "";
}

// ncurses view for the textDisplay
void TextDisplay::ncursesView() {
    clear();
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            string ch = theDisplay[r][c];
            if (ch == "@" || ch == "/") {
                attron(COLOR_PAIR(4));
                printw ("%s", ch.c_str());
                attron(COLOR_PAIR(1));
            }
            else {
                printw ("%s", ch.c_str());
            }
        }
        printw ("\n");
    }
    ostringstream gold, level, hp, atk, def;
    gold << pc->get_gold();
    level << pc->get_level();
    hp << pc->get_hp();
    atk << pc->get_atk();
    def << pc->get_def();
    printw (("Race: " + pc->getRace() + " "  + "Gold: " + gold.str()).c_str());
    printw (("                                               floor " + level.str() + "\n").c_str());
    printw (("HP: " + hp.str() + "\n").c_str());
    printw (("Atk: " + atk.str() + "\n").c_str());
    printw (("Def: " + def.str() + "\n").c_str());
    printw (("Action: " + Action + "\n").c_str());
    
}

// output overloading for displaying the grid
std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
    const int row = td.getRow();
    const int col = td.getCol();
    const player *tempPc = td.getPc();
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            out << td.getType(r, c);
        }
        out << endl;
    }

    out << "Race: " << tempPc->getRace() << " Gold: " << tempPc->get_gold();
    out << setw(50) << "floor " << tempPc->get_level() << endl;
    out << "HP: " << tempPc->get_hp() << endl;
    out << "Atk: " << tempPc->get_atk() << endl;
    out << "Def: " << tempPc->get_def() << endl;
    out << "Action: " << td.getAct() << endl;
    out << "\r" ;
    
    return out;
}
