#include "ClapTrap.hpp"

int	main (void)
{
	ClapTrap	a("younghoc");
	ClapTrap	b("sungyoon");

	a.attack("sungyoon");
	b.takeDamage(a.getAttackValue());
	b.beRepaired(a.getAttackValue());
	b.attack("younghoc");
	a.takeDamage(b.getAttackValue());

	return 0;
}
