#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : value(0)
{
}

Fixed::Fixed(const Fixed &fixed)
{
	if (this != &fixed)
		*this = fixed;
}

Fixed &Fixed::operator =(const Fixed &fixed)
{
	if (this != &fixed)
		value = fixed.getRawBits();
	return *this;
}

Fixed::Fixed(const int &_int)
{
	value = _int * (1 << bit);
}

Fixed::Fixed(const float &_float)
{
	value = roundf(_float * (1 << bit));
}

Fixed::~Fixed(void)
{
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

bool	Fixed::operator >(const Fixed &fixed)
{
	return value > fixed.getRawBits();
}

bool	Fixed::operator <(const Fixed &fixed)
{
	return value < fixed.getRawBits();
}

bool	Fixed::operator >=(const Fixed &fixed)
{
	return value >= fixed.getRawBits();
}

bool	Fixed::operator <=(const Fixed &fixed)
{
	return value <= fixed.getRawBits();
}

bool	Fixed::operator ==(const Fixed &fixed)
{
	return value == fixed.getRawBits();
}

bool	Fixed::operator !=(const Fixed &fixed)
{
	return value != fixed.getRawBits();
}

std::ostream	&operator <<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

float	Fixed::operator +(const Fixed &fixed)
{
	return toFloat() + fixed.toFloat();
}

float	Fixed::operator -(const Fixed &fixed)
{
	return toFloat() - fixed.toFloat();
}

float	Fixed::operator *(const Fixed &fixed)
{
	return toFloat() * fixed.toFloat();
}

float	Fixed::operator /(const Fixed &fixed)
{
	float	f_rawbit;

	f_rawbit = fixed.toFloat();
	return f_rawbit == 0 ? 0 : toFloat() / f_rawbit;
}

Fixed	&Fixed::operator ++(void)
{
	++value;
	return *this;
}

Fixed	&Fixed::operator --(void)
{
	--value;
	return *this;
}

Fixed	Fixed::operator ++(int)
{
	Fixed	old = *this;
	operator++();
	return old;
}

Fixed	Fixed::operator --(int)
{
	Fixed	old = *this;
	operator--();
	return old;
}

Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	std::cout << "min: ";
	return fixed1 < fixed2 ? fixed1 : fixed2;
}

Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	std::cout << "max: ";
	return fixed1 > fixed2 ? fixed1 : fixed2;
}

const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	std::cout << "const min: ";
	return fixed1.getRawBits() < fixed2.getRawBits() ? fixed1 : fixed2;
}

const Fixed	&Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	std::cout << "const max: ";
	return fixed1.getRawBits() > fixed2.getRawBits() ? fixed1 : fixed2;
}
