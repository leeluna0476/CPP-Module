#include "iter.hpp"
#include <iostream>
#include <cstring>

int	main(void)
{
	int	i_array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	void	(*i_print)(int) = print<int>;
	iter(i_array, sizeof(i_array) / sizeof(int), i_print);

	std::cout << std::endl;

	const char*	str = "Hello world";
	void	(*c_print)(char) = print<char>;
	iter(const_cast<char*>(str), std::strlen(str), c_print);

	std::cout << std::endl;

	return 0;
}
