#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a(Fixed(5.05f) * Fixed(2));
	Fixed const b(2);

	std::cout << "-----Logical operation-----" << std::endl;
	std::cout << a << " > " << b << ": " << std::boolalpha << (a > b) << std::endl;
	std::cout << a << " < " << b << ": " << std::boolalpha << (a < b) << std::endl;
	std::cout << a << " >= " << b << ": " << std::boolalpha << (a >= b) << std::endl;
	std::cout << a << " <= " << b << ": " << std::boolalpha << (a <= b) << std::endl;
	std::cout << a << " == " << b << ": " << std::boolalpha << (a == b) << std::endl;
	std::cout << a << " != " << b << ": " <<  std::boolalpha << (a != b) << std::endl;

	std::cout << "-----4 arithmetic operation-----" << std::endl;
	std::cout << a << " + " << b << ": " <<  a + b << std::endl;
	std::cout << a << " - " << b << ": " <<  a - b << std::endl;
	std::cout << a << " * " << b << ": " << a * b << std::endl;
	std::cout << a << " / " << b << ": " << a / b << std::endl;

	a.setRawBits(0);
	std::cout << "-----4 increment/decrement(pre/post) operation-----" << std::endl;
	std::cout << "++" << a << ": " << ++a << std::endl;
	std::cout << a << "++" << ": " << a++ << std::endl;
	std::cout << a << ": " << a << std::endl;

	std::cout << "--" << a << ": " << --a << std::endl;
	std::cout << a << "--" << ": " << a-- << std::endl;
	std::cout << a << ": " << a << std::endl;

	std::cout << "-----min/max comparison-----" << std::endl;
	std::cout << a << ", " << b << ": " << Fixed::min(a, b) << std::endl;
	std::cout << a << ", " << b << ": " << Fixed::max(a, b) << std::endl;

	return 0;
}
