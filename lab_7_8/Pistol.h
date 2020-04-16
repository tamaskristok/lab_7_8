#pragma once
#include <iostream>
#include <string>
#include "Weapon.h"


class Pistol : public Weapon
{
private:
    int clipSize;
    int bulletsInClip;
    int totalBullets;
public:
    Pistol(unsigned int dmg = 60, int cs = 12, int bc = 12, int tb = 48) :Weapon(dmg)
    {
        clipSize = cs;
        bulletsInClip = bc;
        totalBullets = tb;
    }
    void reload();
    unsigned int use();
    int get_clipSize();
    int get_bulletsInClip();
    int get_totalBullets();
    void set_clipSize(int a);
    void set_bulletsInClip(int a);
    void set_totalBullets(int a);


    std::string toString();
};
