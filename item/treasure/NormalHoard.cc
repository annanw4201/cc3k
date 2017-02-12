//
//  NormalHoard.cpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "NormalHoard.h"
#include "../../character/player/player.h"

NormalHoard::NormalHoard():Treasure("NormalHoard") {}

NormalHoard::~NormalHoard() {}

int NormalHoard::get_row() const {
    return 0;
}

int NormalHoard::get_col() const {
    return 0;
}

void NormalHoard::Take_Treasure(player *pc) {
    pc->change_gold(amt);
}

void NormalHoard::UpdatePos(const int &r, const int &c) {
    
}

void NormalHoard::setDragon(enemy *dragon) {
    
}
