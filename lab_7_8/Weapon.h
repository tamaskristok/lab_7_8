#pragma once
#include <iostream>
#include <string>
class Weapon
{
private:
	unsigned int damage;
public:
	Weapon(int dmg = 10);
	unsigned int get_damage() { return damage; }
	void set_damage(unsigned int dmg);
	virtual unsigned int use();
	bool validate_input(unsigned int dmg);

	virtual std::string toString();
};
