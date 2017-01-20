#ifndef ELF_H
#define ELF_H

#include "enemy.h"

class Elf : public enemy
{
    bool hostile;
public:
    /** Default constructor */
    Elf();
    /** Default destructor */
    ~Elf();
    void attack (Character *defender) override;
    void attackby (Character * attacker) override;
    void guardTreasure (Treasure *dh) override;
    bool is_hostile () const override;
};

#endif // ELF_H
