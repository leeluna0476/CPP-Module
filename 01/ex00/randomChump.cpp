#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	_new(name);

	_new.announce();
}
