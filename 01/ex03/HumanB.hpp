#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include "Weapon.hpp"
#include <string>

class	HumanB
{
	private:
		std::string	name;
		Weapon	*weapon;
	
	public:
		HumanB();
		HumanB(const std::string &_name);
		~HumanB();

		void	setWeapon(Weapon &_weapon);
		void	attack(void);
};

#endif
