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

ClapTrap &ClapTrap::operator =(const ClapTrap &claptrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = claptrap._name;
	this->_hit = claptrap._hit;
	this->_energy = claptrap._energy;
	this->_attack = claptrap._attack;
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_hit && _energy)
	{
		std::cout << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << std::endl;
		--_energy;
	}
	else
	{
		if (!_hit) std::cout << _name << ": " << "No health to attack" << std::endl;
		else if (!_energy) std::cout << _name << ": " << "No energy to attack" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit >= amount) _hit -= amount;
	else _hit = 0;
	std::cout << _name << ": " << amount << " points have been damaged and " << _hit << " hit points are left" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy)
	{
		if (~(unsigned int)0 - amount >= _hit) _hit += amount;
		else _hit = ~(unsigned int)0;
		--_energy;
		std::cout << _name << ": " << amount << " points have been restored and " << _hit << " hit points are left" << std::endl;
	}
	else
		std::cout << _name << ": " << "No energy to repair" << std::endl;
}

unsigned int	ClapTrap::getAttackValue(void) const
{
	return _attack;
}
