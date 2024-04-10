#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*(other.brain));
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	Animal::operator=(other);
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "A cat meows" << std::endl;
}
