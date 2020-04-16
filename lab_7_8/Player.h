#pragma once
#include "Weapon.h"
class Player
{
private:
    std::string name;
    unsigned health;
    unsigned maxWeaponsCount;
    int weaponsCount;
    Weapon** weapons;
    unsigned selectedWeaponIndex;

public:
    Player(std::string name = "Unknown Soldier", unsigned health = 100, unsigned maxWeaponsCount = 5, Weapon* weapon = NULL);
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