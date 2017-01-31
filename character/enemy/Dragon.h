#ifndef DRAGON_H
#define DRAGON_H

#include "enemy.h"

class Tresure;
class DragonHoard;

class Dragon : public enemy
{
    bool hostile;
    DragonHoard *dh;
public:
    /** Default constructor */
    Dragon();
    /** Default destructor */
    ~Dragon();
    void attack (Character *defender) override;
    void attackby (Character * attacker) override;
    void guardTreasure (Treasure *dh) override;
    DragonHoard *getDragonHoard ();
    bool is_hostile () const override;
};

#endif // DRAGON_H
