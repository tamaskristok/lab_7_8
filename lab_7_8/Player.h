#pragma once
#include "Weapon.h"
#include <string>

class Player
{
private:
    std::string name;
    unsigned health;
    unsigned maxWeaponsCount;
    int weaponsCount;
    Weapon** weapons;
    unsigned selectedWeaponIndex;
    /*std::string name, unsigned health=100,unsigned maxWeaponsCount=5, Weapon* weapon=nullptr )*/
public:
    Player(std::string name = "Unknown Soldier", unsigned health = 100, unsigned maxWeaponsCount = 5, Weapon* weapon = NULL) : name(name), health(health), maxWeaponsCount(maxWeaponsCount)  {
        weaponsCount = 0;
        setName(name);
        equipWeapon(weapon);
    }
    ~Player();

    std::string getName() const;
    void setName(std::string name);
    unsigned getWeaponsCount() const;
    Weapon* getSelectedWeapon() const;
    unsigned getHealth() const;
    bool equipWeapon(Weapon* weapon);
    bool dropSelected();
    bool switchToNextWeapon();
    bool switchToPreviousWeapon();
    bool takeDamage(unsigned damage);
    bool attack(Player& enemy) const;
    bool isAlive() const;
};

std::ostream& operator<<(std::ostream&, const Player&);