#ifndef DWARF_H
#define DWARF_H

#include "enemy.h"

class Dwarf : public enemy
{
    bool hostile;
public:
    /** Default constructor */
    Dwarf();
    /** Default destructor */
    ~Dwarf();
    void attack (Character *defender) override;
    void attackby (Character * attacker) override;
    void guardTreasure (Treasure *dh) override;
    bool is_hostile () const override;

};
#endif // DWARF_H
