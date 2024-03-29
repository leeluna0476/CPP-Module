#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : __name("zombie")
{
}

Zombie::Zombie(const std::string &_name) : __name(_name)
{
}

Zombie::~Zombie()
{
	std::cout << __name << "is destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << __name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
