#ifndef HALFLING_H
#define HALFLING_H

#include "enemy.h"

class Halfling : public enemy
{
    bool hostile;
public:
    /** Default constructor */
    Halfling();
    /** Default destructor */
    ~Halfling();
    void attack (Character *defender) override;
    void attackby (Character * attacker) override;
    void guardTreasure (Treasure *dh) override;
    bool is_hostile () const override;
};

#endif // HALFLING_H
