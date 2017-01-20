#include "troll.h"
#include <math.h>
using namespace std;

const int troll_max_hp = 120;
const int troll_atk = 25;
const int troll_def = 15;
const int troll_restore_hp = 5;

troll::troll():
player("Troll", troll_max_hp, troll_atk, troll_def, 0) {}

troll::~troll()
{
    //dtor
}

void troll::change_hp(const int &value) {
    int tempHp = ceil (hp + value);
    if (tempHp >= troll_max_hp) {
        hp = troll_max_hp;
        td->updateAct("PC reaches Maximum Health. ");
    }
    else if (tempHp <= 0) {
        hp = 0;
    }
    else {
        hp = tempHp;
    }
}

void troll::change_atk(const int &value) {
    tempAtk += value;
    atk = tempAtk + troll_atk;
}

void troll::change_def(const int &value) {
    tempDef += value;
    def = tempDef + troll_def;
}

void troll::change_gold(const int &value) { gold += value;}

void troll::steal_gold() {}

void troll::move(const string &input) {
    hp += troll_restore_hp;
    if (hp < troll_max_hp) {
    ostringstream num_to_str;
    num_to_str << troll_restore_hp;
    td->updateAct("PC restores " + num_to_str.str() + " HP. ");
    }
    if (hp >= troll_max_hp) {
        hp = troll_max_hp;
        td->updateAct("PC reaches maximun health. ");
    }
    if(input == "North") {--row;}
    else if(input == "South") {++row;}
    else if(input == "West") {--col;}
    else if(input == "East") {++col;}
    else if(input == "NorthWest") {--row; --col;}
    else if(input == "NorthEast") {--row; ++col;}
    else if(input == "SouthWest") {++row; --col;}
    else if(input == "SouthEast") {++row; ++col;}
}
