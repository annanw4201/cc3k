//
//  Treasure.hpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef Treasure_hpp
#define Treasure_hpp

#include <string>
#include "../Item.h"

class player;
class enemy;

class Treasure: public Item {
    std::string type, name;
public:
    Treasure (const std::string &name);
    virtual ~Treasure();
    std::string getType() const;
    std::string getRace() const;
    virtual int get_row() const = 0;
    virtual int get_col() const = 0;
    virtual void Take_Treasure (player *pc) = 0;
    virtual void setDragon(enemy *dragon) = 0;
};
#endif /* Treasure_hpp */
