#include "Knife.h"

void Knife::sharpen()
{
    /*
     * One sharpening adds 10% more to the factor
     * also check if exceeds the maximum value
     */
    sharpness *= 1.1;

    if (sharpness > 1) {
        sharpness = 1;
    }
}

unsigned int Knife::use()
{
    Weapon::use();
    sharpness *= 0.95;

    return (unsigned int)sharpness * this->get_damage();
}


std::string Knife::toString()
{
    return "Knife";
}


double Knife::get_sharpness()
{
    return this->sharpness;
}

void Knife::set_sharpness(double shrp)
{
    if (shrp < 0 || shrp > 1)
    {
        /* do nothing */
    }
    else
    {
        sharpness = shrp;
    }

}

