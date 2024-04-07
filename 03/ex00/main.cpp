#include "ClapTrap.hpp"

int	main (void)
{
	ClapTrap	a("younghoc");
	ClapTrap	b("sungyoon");
//	ClapTrap	c;
//
//	c = a;

	a.attack("sungyoon");
	b.takeDamage(a.getAttackValue());
	b.beRepaired(a.getAttackValue());
	b.attack("younghoc");
	a.takeDamage(b.getAttackValue());

	return 0;
}
