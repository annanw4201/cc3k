//
//  SmallHoard.cpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "SmallHoard.h"
#include "../../character/player/player.h"

SmallHoard::SmallHoard(): Treasure("SmallHoard") {}

SmallHoard::~SmallHoard() {}

int SmallHoard::get_row() const {
    return 0;
}

int SmallHoard::get_col() const {
    return 0;
}

void SmallHoard::Take_Treasure(player *pc) {
    pc->change_gold(amt);
}

void SmallHoard::UpdatePos (const int &r, const int &c) {

}

void SmallHoard::setDragon(enemy *dragon) {
    
}
