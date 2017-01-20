#ifndef HUMAN_H
#define HUMAN_H

#include "enemy.h"

class Human : public enemy
{
    bool hostile;
public:
    /** Default constructor */
    Human();
    /** Default destructor */
    ~Human();
    void attack (Character *defender) override;
    void attackby (Character * attacker) override;
    void guardTreasure (Treasure *dh) override;
    bool is_hostile () const override;
};
#endif // HUMAN_H
