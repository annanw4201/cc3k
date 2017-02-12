//
//  DragonHoard.hpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef DragonHoard_hpp
#define DragonHoard_hpp

#include "Treasure.h"

class enemy;

class DragonHoard : public Treasure {
    int amt = 6;
    int r, c;
    enemy *dragon;
    bool is_dragon_died;
public:
    DragonHoard();
    ~DragonHoard();
    bool dragon_died() const;
    enemy * getDragon() const;
    int get_row() const override;
    int get_col() const override;
    void change_dragon_died();
    void setDragon (enemy *dragon) override;
    void Take_Treasure (player *pc) override;
    void UpdatePos (const int &, const int &) override;
};
#endif /* DragonHoard_hpp */
