#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	// HumanA always takes a weapon
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	// HumanB may not always take a weapon
	{
		// HumanB with weapon set
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
//	std::string에서 segmentation fault 발생
//	{
//		Weapon club = Weapon("crude spiked club");
//		HumanA haley(NULL, club);
//	}
	{
		// HumanB without weapon set
		HumanB mike("Mike");
		mike.attack();
	}
	return 0;
}
