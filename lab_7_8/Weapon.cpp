#include "Weapon.h"

Weapon::Weapon(int dmg)
{
    if (validate_input(dmg))
    {
        damage = dmg;
    }
    else
    {
        damage = 10;
    }
}

void Weapon::set_damage(unsigned int dmg)
{
    if (validate_input(dmg))
    {
        damage = dmg;
    }
}



bool Weapon::validate_input(unsigned int dmg)
{
    if (dmg < 0 || dmg > 100)
    {
        return false;
    }

    return true;
}

std::string Weapon::toString()
{
    return "=================================\nDamage: " + std::to_string(damage);
}


unsigned int Weapon::use()
{
    damage--;
    if (damage < 0 || damage > 100)
    {
        damage = 0;
    }
    return damage;
}