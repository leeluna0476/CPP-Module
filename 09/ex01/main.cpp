#include "RPN.hpp"
#include <iostream>
#include <exception>

int	main(int ac, char **av)
{
    if (ac != 2)
    {
        return 0;
    }

    RPN rpn;

	try
	{
    rpn.calculate(av[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
