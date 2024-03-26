#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA() : name(""), weapon(NULL)
{
}

HumanA::HumanA(const std::string &_name, Weapon &_weapon)
{
	name = _name;
	weapon = &_weapon;
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void)
{
	std::cout << name << ": attacks with their " << weapon->getType() << std::endl;
}
