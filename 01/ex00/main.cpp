#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	Zombie	stack_zombie("szombie");
	Zombie	*heap_zombie = newZombie("hzombie");
	randomChump("tzombie");

	stack_zombie.announce();
	heap_zombie->announce();

	delete heap_zombie;
}
