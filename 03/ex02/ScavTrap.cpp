#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hit = 100;
	_energy = 50;
	_attack = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "ScavTrap conversion constructor called" << std::endl;
	_hit = 100;
	_energy = 50;
	_attack = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator =(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	_name = other._name;
	_hit = other._hit;
	_energy = other._energy;
	_attack = other._attack;
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
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

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
