#include "Weapon.hpp"

Weapon::Weapon() : __type("weapon")
{
}

Weapon::Weapon(const std::string &_type)
{
	__type = _type;
}

Weapon::~Weapon()
{
}

std::string	Weapon::getType(void)
{
	return __type;
}

void	Weapon::setType(const std::string &_type)
{
	__type = _type;
}
