#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &_name, Weapon &_weapon) : __name(_name), __weapon(_weapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void)
{
	std::cout << __name << ": attacks with their " << __weapon.getType() << std::endl;
}
