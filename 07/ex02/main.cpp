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

		Array<int>	i_2;
		std::cout << "i_2: " << i_2.size() << std::endl;

		i_2 = i_array;
		std::cout << "i_2: " << i_2.size() << std::endl;

		for (unsigned int i = 0; i < size; i++)
		{
			std::cout << i_2[i] << ' ';
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
