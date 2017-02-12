//
//  MerchantHoard.cpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "MerchantHoard.h"
#include "../../character/player/player.h"

MerchantHoard::MerchantHoard(): Treasure("MerchantHoard") {}

MerchantHoard::~MerchantHoard() {}

int MerchantHoard::get_row() const {
    return 0;
}

int MerchantHoard::get_col() const {
    return 0;
}

void MerchantHoard::Take_Treasure(player *pc) {
    pc->change_gold(amt);
}

void MerchantHoard::UpdatePos (const int &, const int &) {
}

void MerchantHoard::setDragon(enemy *dragon) {
    
}
