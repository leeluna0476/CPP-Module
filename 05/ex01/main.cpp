#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void	terminateProgram(void);

int	main(void)
{
	std::set_terminate(terminateProgram);
	try
	{
		Form		form("jungyeok", 10, 15);
//		Form		form("jungyeok", -1, 15);
		Bureaucrat	minjungk("minjungk", 60);
//		Bureaucrat	yonghyle("minjungk", -1);

		std::cout << minjungk << std::endl;
		minjungk.signForm(form);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << ": Couldn't instanciate the object" << std::endl;
		return 1;
	}
	return 0;
}

void	terminateProgram(void)
{
	std::cerr << "Cannot catch an error" << std::endl;
	exit(1);
}
