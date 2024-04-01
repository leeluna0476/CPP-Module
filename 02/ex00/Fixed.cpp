#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) : value(fixed.value)
{
	std::cout << "Copy constructor called" << std::endl;
}

void Fixed::operator =(Fixed &fixed)
{
	value = fixed.value;
	std::cout << "Copy assignment operator called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
