#pragma once
#include "Weapon.h"
#include <iostream>
#include <string>

class Knife : public Weapon
{
private:
	double sharpness;
public:
	Knife(unsigned int damage = 30, double sharp = 0.8) : Weapon(damage) { sharpness = sharp; }
	void sharpen();
	unsigned int use();
	double get_sharpness();
	void set_sharpness(double shrp);
	std::string toString();
};