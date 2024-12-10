#include <iostream>
#include "whatever.hpp"

int	main(void)
{
	int	a = 1;
	int	b = 3;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	std::cout << min(a, b) << std::endl;
	std::cout << max(a, b) << std::endl;

	swap(a, b);

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	return 0;
}
