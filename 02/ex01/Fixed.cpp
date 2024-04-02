#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &fixed)
		*this = fixed;
}

Fixed &Fixed::operator =(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		value = fixed.getRawBits();
	return *this;
}

Fixed::Fixed(const int &_int)
{
	std::cout << "Int constructor called" << std::endl;
	value = _int << bit;
}

Fixed::Fixed(const float &_float)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(_float * (1 << bit));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return value;
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

int	Fixed::toInt(void) const
{
	return value >> bit;
}

float	Fixed::toFloat(void) const
{
	return (float)value / (1 << bit);
}

std::ostream	&operator <<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
