#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB() : name(""), weapon(NULL)
{
}

HumanB::HumanB(const std::string &_name) : weapon(NULL)
{
	name = _name;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon &_weapon)
{
	weapon = &_weapon;
}

void	HumanB::attack(void)
{
	if (weapon)
	{
		std::cout << name << ": attacks with their " << weapon->getType() << std::endl;
	}
	else
		std::cout << "No weapon set" << std::endl;
}
