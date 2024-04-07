#include "FragTrap.hpp"

int	main (void)
{
	FragTrap	a("hyeongsh");
	FragTrap	b("minjungk");
	FragTrap	c("jjhang");
//	FragTrap	b(a);
//	FragTrap	c;
//
//	c = a;
	c.attack("hyeongsh");
	a.takeDamage(c.getAttackValue());
	b.attack("hyeongsh");
	a.takeDamage(c.getAttackValue());

	c.highFiveGuys();

	return 0;
}
