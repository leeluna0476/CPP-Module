#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"
#include <string>

class	HumanA
{
	private:
		std::string	__name;
		Weapon		&__weapon;
	
	public:
		HumanA(const std::string &_name, Weapon &_weapon);
		~HumanA();

		void		attack(void);
};

#endif
