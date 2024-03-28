#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB() : __name(""), __weapon(NULL)
{
}

HumanB::HumanB(const std::string &_name) : __weapon(NULL)
{
	__name = _name;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon &_weapon)
{
	__weapon = &_weapon;
}

void	HumanB::attack(void)
{
	if (__weapon)
		std::cout << __name << ": attacks with their " << __weapon->getType() << std::endl;
	else
		std::cout << "No weapon set" << std::endl;
}
