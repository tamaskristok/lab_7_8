#include "Railgun.h"

unsigned int Railgun::use()
{
    Weapon::use();
    this->set_damage(this->get_damage() - 1);
    this->energy -= 10;
    if (this->energy < 0)
    {
        this->energy = 0;
        return 0;
    }
    return this->get_damage();
}


void Railgun::recharge()
{
    this->energy += 8;
    if (this->energy > 100)
    {
        this->energy = 100;
    }
}

std::string Railgun::toString()
{
    return Weapon::toString() + "\nRailgun energy:" + std::to_string(this->energy);
}

void Railgun::set_energy(int eng)
{
    if (eng >= 0 && eng <= 100)
    {
        this->energy = eng;
    }
}

int Railgun::get_energy()
{
    return energy;
}
