//
//  MakeFloor.hpp
//  test
//
//  Created by Wang Annan on 2016-11-20.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef MakeFloor_hpp
#define MakeFloor_hpp

#include <string>

class Floortiles;

class MakeFloor {
public:
    Floortiles *CreateTiles(const std::string &type);
    
};

#endif /* MakeFloor_hpp */
