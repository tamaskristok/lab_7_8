#include "Pistol.h"
void Pistol::reload()
{
    bulletsInClip = 0;
    totalBullets -= clipSize;
    if (totalBullets < 0)
    {
        bulletsInClip = clipSize + totalBullets;
        totalBullets = 0;
    }
    else {
        bulletsInClip += clipSize;
    }
}

unsigned int Pistol::use()
{
    Weapon::use();
    if (bulletsInClip == 0)
    {
        return 0;
    }
    bulletsInClip--;
    return this->get_damage();

}

std::string Pistol::toString()
{
    return "Pistol";
}

int Pistol::get_clipSize()
{
    return this->clipSize;
}

int Pistol::get_bulletsInClip()
{
    return this->bulletsInClip;
}

int Pistol::get_totalBullets()
{
    return this->totalBullets;
}

void Pistol::set_clipSize(int a)
{
    this->clipSize = a;
}

void  Pistol::set_bulletsInClip(int a)
{

    this->bulletsInClip = a;
}

void Pistol::set_totalBullets(int a)
{
    this->totalBullets = a;
}

