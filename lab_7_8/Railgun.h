#pragma once
#include "Weapon.h"
#include <string>

class Railgun : public Weapon
{
private:
    int energy;
public:
    Railgun(unsigned int dmg = 90, int eg = 100) :Weapon(dmg)
    {
        energy = eg;
    }
    unsigned int use();
    int get_energy();
    void set_energy(int eng);

    void recharge();
    std::string toString();
};
