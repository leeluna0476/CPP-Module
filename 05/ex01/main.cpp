#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void	terminateProgram(void);

int	main(void)
{
	Form		form("form", 10, 15);
	Bureaucrat	minjungk("minjungk", 3);
	return 0;
}

void	terminateProgram(void)
{
	std::cerr << "Cannot catch an error" << std::endl;
	exit(1);
}
