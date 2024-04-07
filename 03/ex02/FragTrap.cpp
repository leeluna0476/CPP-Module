#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
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

void	FragTrap::highFiveGuys(void)
{
	std::cout << "Let's make a high-five, guys!" << std::endl;
}
