#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _name("seojilee"), _hit(10), _energy(10), _attack(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap) : _name(claptrap._name), _hit(claptrap._hit), _energy(claptrap._energy), _attack(claptrap._attack)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hit(10), _energy(10), _attack(0)
{
	std::cout << "Conversion constructor called" << std::endl;
}

ClapTrap ClapTrap::operator =(const ClapTrap &claptrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	return ClapTrap(claptrap);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_energy)
	{
		std::cout << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << std::endl;
		--_energy;
	}
	else
		std::cout << _name << ": " << "No energy to attack" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hit -= amount;
	std::cout << _name << ": " << amount << " points have been damaged and " << _hit << " hit points are left" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy)
	{
		_hit += amount;
		--_energy;
		std::cout << _name << ": " << amount << " points have been restored and " << _hit << " hit points are left" << std::endl;
	}
	else
		std::cout << _name << ": " << "No energy to repair" << std::endl;
}

unsigned int	ClapTrap::getAttackValue(void)
{
	return _attack;
}
