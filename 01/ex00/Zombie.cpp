#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("zombie")
{
}

Zombie::Zombie(const std::string &_name)
{
	name = _name;
}

Zombie::~Zombie()
{
	std::cout << name << "is destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
