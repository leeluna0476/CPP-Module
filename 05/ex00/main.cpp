#include "Bureaucrat.hpp"
#include <iostream>

void	terminateProgram(void);

int	main(void)
{
	std::set_terminate(terminateProgram);

	try
	{
		Bureaucrat	a("wocheon", 2);
		Bureaucrat	b("jasong", 160);
		--a;
		++b;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}

void	terminateProgram(void)
{
	std::cerr << "Cannot catch an error" << std::endl;
	exit(1);
}
