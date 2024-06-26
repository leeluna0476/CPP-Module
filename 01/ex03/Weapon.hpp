#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class	Weapon
{
	private:
		std::string			__type;

	public:
		Weapon();
		Weapon(const std::string &_type);
		~Weapon();

		const std::string	&getType(void);
		void				setType(const std::string &_type);
};

#endif
