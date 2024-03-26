#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie	*_new;

	_new = new Zombie[N];

	for (int i = 0; i < N; i++)
		_new[i].set_name(name);

	return _new;
}
