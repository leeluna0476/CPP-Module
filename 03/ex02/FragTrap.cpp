#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_hit = 100;
	_energy = 100;
	_attack = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	_hit = 100;
	_energy = 100;
	_attack = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap conversion constructor called" << std::endl;
}

FragTrap &FragTrap::operator =(const FragTrap &other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	_name = other._name;
	_hit = other._hit;
	_energy = other._energy;
	_attack = other._attack;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap: ";
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

void	FragTrap::highFiveGuys(void)
{
	std::cout << "Let's make a high-five, guys!" << std::endl;
}
