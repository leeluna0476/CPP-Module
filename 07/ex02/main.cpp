#include "Array.hpp"
#include <iostream>
#include <exception>

int	main(void)
{
	try
	{
		unsigned int	size = 10;
		Array<int>	i_array(size);

		for (unsigned int i = 0; i < size; i++)
		{
			std::cout << i_array[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << i_array[size] << ' ';
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
