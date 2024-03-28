#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA() : __name(""), weapon(NULL)
{
}

HumanA::HumanA(const std::string &_name, Weapon &_weapon)
{
	__name = _name;
	weapon = &_weapon;
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void)
{
	std::cout << __name << ": attacks with their " << weapon->getType() << std::endl;
}
