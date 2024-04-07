#include "ScavTrap.hpp"

int	main (void)
{
	ScavTrap	a("semjeong");
	ScavTrap	b(a);
	ScavTrap	c;

	c = a;
	c.attack("semjeong");
	a.takeDamage(c.getAttackValue());
	b.attack("semjeong");
	a.takeDamage(c.getAttackValue());

	c.guardGate();

	return 0;
}
