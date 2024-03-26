#include "Weapon.hpp"

Weapon::Weapon() : type("weapon")
{
}

Weapon::Weapon(const std::string &_type)
{
	type = _type;
}

Weapon::~Weapon()
{
}

std::string	Weapon::getType(void)
{
	return type;
}

void	Weapon::setType(const std::string &_type)
{
	type = _type;
}
