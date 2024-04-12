#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void	terminateProgram(void);

int	main(void)
{
	try
	{
		Form		form("form", 10, 15);
		Bureaucrat	minjungk("minjungk", 60);

		std::cout << minjungk << std::endl;
		minjungk.signForm(form);
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
