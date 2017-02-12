//
//  MakeItem.hpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef MakeItem_hpp
#define MakeItem_hpp

class Potion;
class Treasure;

class MakeItem {
public:
    Potion * CreatePotion (const int &num_translate);
    Treasure * CreateTreasure (const int &num_translate);
};

#endif /* MakeItem_hpp */
