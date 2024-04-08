#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : type("Parastratiosphecomyia stratiosphecomyioides")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "An animal makes sound" << std::endl;
}

std::string	Animal::getType(void) const
{
	return type;
}
