#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main (void)
{
	ScavTrap	a("jungyeok");
	ScavTrap	b("semjeong");
	ScavTrap	c("chunsik");
//	ScavTrap	b(a);
//	ScavTrap	c;
//
//	c = a;
	c.attack("jungyeok");
	a.takeDamage(c.getAttackValue());
	b.attack("jungyeok");
	a.takeDamage(c.getAttackValue());

	c.guardGate();

	return 0;
}
