//
//  MakeCharacter.hpp
//  test
//
//  Created by Wang Annan on 2016-11-22.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef MakeCharacter_hpp
#define MakeCharacter_hpp

#include <string>
class player;
class enemy;

class Character;

class MakeCharacter{
public:
    player * CreatePlayer(const std::string &race);
    enemy * CreateEnemy(const std::string &race);
};

#endif /* MakeCharacter_hpp */
