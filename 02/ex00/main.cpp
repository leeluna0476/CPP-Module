#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a;    // Default constructor
	Fixed b(a); // Copy constructor
	Fixed c;    // Default constructor

	c = b;      // Copy assignment operator, getRawBits

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	c.setRawBits(10);
	std::cout << c.getRawBits() << std::endl;
	return 0;
}	
