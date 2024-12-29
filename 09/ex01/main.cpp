#include "RPN.hpp"

int	main(int ac, char **av)
{
    if (ac != 2)
    {
        return 0;
    }

    RPN rpn;

    rpn.calculate(av[1]);
	return 0;
}
