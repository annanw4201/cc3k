//
//  MerchantHoard.hpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef MerchantHoard_hpp
#define MerchantHoard_hpp

#include "Treasure.h"

class enemy;

class MerchantHoard : public Treasure {
    int amt = 4;
public:
    MerchantHoard();
    ~MerchantHoard();
    int get_row() const override;
    int get_col() const override;
    void Take_Treasure(player *pc) override;
    void UpdatePos (const int &, const int &) override;
    void setDragon (enemy *dragon) override;
};

#endif /* MerchantHoard_hpp */
