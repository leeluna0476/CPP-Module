#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"
#include <string>

class	HumanA
{
	private:
		std::string	name;
		Weapon	*weapon;
	
	public:
		HumanA();
		HumanA(const std::string &_name, Weapon &_weapon);
		~HumanA();

		void	attack(void);
};

#endif
