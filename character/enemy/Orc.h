#ifndef ORC_H
#define ORC_H

#include "enemy.h"

class Orc : public enemy
{
    bool hostile;
public:
    /** Default constructor */
    Orc();
    /** Default destructor */
    ~Orc();
    void attack (Character *defender) override;
    void attackby (Character * attacker) override;
    void guardTreasure (Treasure *dh) override;
    bool is_hostile () const override;
};
#endif // ORC_H
