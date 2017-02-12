//
//  SmallHoard.hpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef SmallHoard_hpp
#define SmallHoard_hpp

#include "Treasure.h"

class enemy;

class SmallHoard : public Treasure {
    int amt = 1;
public:
    SmallHoard();
    ~SmallHoard();
    int get_row() const override;
    int get_col() const override;
    void Take_Treasure(player *pc) override;
    void UpdatePos (const int &, const int &) override;
    void setDragon (enemy *dragon) override;
};

#endif /* SmallHoard_hpp */
