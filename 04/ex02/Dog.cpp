#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	if (this != &other)
		brain = new Brain(*(other.brain));
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete brain;
		brain = new Brain(*(other.brain));
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "A dog barks" << std::endl;
}

std::string	Dog::getType(void) const
{
	return type;
}
