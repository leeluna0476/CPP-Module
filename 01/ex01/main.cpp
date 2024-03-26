#include "Zombie.hpp"

int	main(void)
{
	Zombie		*_zombies;
	const int	n = 10;

	_zombies = zombieHorde(n, "mzombies");

	for (int i = 0; i < n; i++)
		_zombies[i].announce();

	delete[] _zombies;
	
	return 0;
}
