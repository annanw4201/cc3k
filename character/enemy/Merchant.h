#ifndef MERCHANT_H
#define MERCHANT_H

#include "enemy.h"


class Merchant : public enemy
{
    static bool hostile;
public:
    /** Default constructor */
    Merchant();
    /** Default destructor */
    ~Merchant();
    void attack (Character *defender) override;
    void attackby (Character * attacker) override;
    void guardTreasure (Treasure *dh) override;
    bool is_hostile()const override;

};

#endif // MERCHANT_H
