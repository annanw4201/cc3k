#include "goblin.h"
#include <math.h>
using namespace std;

const int goblin_max_hp = 110;
const int goblin_atk = 150;
const int goblin_def = 20;
const int goblin_stealGold = 5;

goblin::goblin():
player("Goblin", goblin_max_hp, goblin_atk, goblin_def, 0) {}

goblin::~goblin()
{
    //dtor
}

void goblin::change_hp(const int &value) {
    int tempHp = ceil (hp + value);
    if (tempHp >= goblin_max_hp) {
        hp = goblin_max_hp;
        td->updateAct("PC reaches Maximum Health. ");
    }
    else if (tempHp <= 0) {
        hp = 0;
    }
    else {
        hp = tempHp;
    }
}

void goblin::change_atk(const int &value) {
    tempAtk += value;
    atk = tempAtk + goblin_atk;
}

void goblin::change_def(const int &value) {
    tempDef += value;
    def = tempDef + goblin_def;
}

void goblin::change_gold(const int &value) { gold += value;}

void goblin::steal_gold() {
    gold += goblin_stealGold;
}

void goblin::move(const string &input) {
    if(input == "North") {--row;}
    else if(input == "South") {++row;}
    else if(input == "West") {--col;}
    else if(input == "East") {++col;}
    else if(input == "NorthWest") {--row; --col;}
    else if(input == "NorthEast") {--row; ++col;}
    else if(input == "SouthWest") {++row; --col;}
    else if(input == "SouthEast") {++row; ++col;}
}

