#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*_new;

	_new = new Zombie(name);
	return _new;
}
