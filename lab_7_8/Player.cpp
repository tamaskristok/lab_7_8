#include "Player.h"
using namespace std;

Player::Player(std::string name, unsigned health, unsigned maxWeaponsCount, Weapon* weapon)
{
	setName(name);
	equipWeapon(weapon);
	this->health = health;
}


Player::~Player() 
{
	delete[] weapons;
	weapons = nullptr;
}


std::string Player::getName() const
{
	return name;
}

void Player::setName(std::string name)
{
	this->name = name;
}


unsigned Player::getWeaponsCount() const
{
	return weaponsCount;
}

Weapon* Player::getSelectedWeapon() const
{
	if (weaponsCount > 0)
		return weapons[selectedWeaponIndex];
	else
		return nullptr;
}


unsigned Player::getHealth() const
{
	return health;
}

bool Player::equipWeapon(Weapon* weapon)
{
	if (isAlive() == true && weapon != nullptr && weaponsCount < (int)maxWeaponsCount)
	{
		for (int i = 0; i < weaponsCount; i++)
		{
			if (weapons[i] == weapon) { return false; }
		}

		Weapon** newWeapon = new Weapon*[++weaponsCount];
		for (int i = 0; i < weaponsCount-1; i++)
		{
			newWeapon[i] = weapons[i];
		}
		newWeapon[weaponsCount - 1] = weapon;

		delete[] weapons;
		weapons = newWeapon;
		delete[] newWeapon;

		return true;
	}

	return false;
}


bool Player::dropSelected()
{
	if (isAlive() == true && getWeaponsCount() > 0)
	{
		delete weapons[selectedWeaponIndex--];
		weaponsCount--;

		if (weaponsCount > 0)
		{
			Weapon** tomb = new Weapon * [weaponsCount];

			for (int i = 0; i < weaponsCount - 1; i++)
			{
				tomb[i] = weapons[i];
			}

			selectedWeaponIndex = 0;

			weapons = tomb;
		}
		return true;
	}

	return false;
}


bool Player::switchToNextWeapon()
{
	if (isAlive() == true && getWeaponsCount() > 0)
	{
		if (selectedWeaponIndex == weaponsCount -1) /*jump first weapon*/
		{
			selectedWeaponIndex = 0;
		}
		else
		{
			selectedWeaponIndex++;
		}
		return true;
	}
	return false;
}


bool Player::switchToPreviousWeapon()
{
	if (isAlive() == true && getWeaponsCount() > 0)
	{
		if (selectedWeaponIndex == 0) /*jump last weapon*/
		{
			selectedWeaponIndex = weaponsCount-1;
		}
		else
		{
			selectedWeaponIndex--;
		}
		return true;
	}
	return false;
}


bool Player::takeDamage(unsigned damage)
{
	if (isAlive() == true)
	{
		health = getHealth() - damage;
		if (damage > getHealth())
		{
			health = 0;
		}
		return true;
	}
	return false;
}

/*ITT VANNAK GONDOK*/
bool Player::attack(Player& enemy) const
{

	if (isAlive() == true)
	{
		enemy.takeDamage();
		return true;
	}

	return false;
}



bool Player::isAlive() const
{
	if (health > 0)
		return true;
	else
		return false;
}


ostream& operator<<(ostream& os, const Player& right)
{
	if (right.isAlive() && (right.getWeaponsCount() > 0)) {
		os << right.getName() << "is (not) alive; helath: " << right.getHealth() << "; has " << right.getWeaponsCount()
			<< " weapon(s); " << right.getSelectedWeapon() << endl;
		return os;
	}
	if (right.isAlive() && (right.getWeaponsCount() == 0)) {
		os << right.getName() << "is (not) alive; helath: " << right.getHealth() << "; has " << right.getWeaponsCount()
			<< " weapon(s); selected no weapon" << endl;
		return os;
	}
	if (!(right.isAlive()) && (right.getWeaponsCount() > 0)) {
		os << right.getName() << "is (not) alive; helath: " << right.getHealth() << "; has " << right.getWeaponsCount()
			<< " weapon(s); " << right.getSelectedWeapon() << endl;
		return os;
	}
	if (!(right.isAlive()) && (right.getWeaponsCount() == 0)) {
		os << right.getName() << "is (not) alive; helath: " << right.getHealth() << "; has " << right.getWeaponsCount()
			<< " weapon(s); selected no weapon" << endl;
		return os;
	}
}