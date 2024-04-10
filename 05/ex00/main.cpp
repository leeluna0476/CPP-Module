#include "Bureaucrat.hpp"
#include <iostream>

void	terminateProgram(void);

int	main(void)
{
	std::set_terminate(terminateProgram);
//	Bureaucrat	a;
//
//	try
//	{
//		--a; // current grade == 150
//	}
//	catch (Bureaucrat::GradeTooLowException& e)
//	{
//		std::cerr << e.what() << std::endl;
//		return 1;
//	}
//	catch (Bureaucrat::GradeTooHighException& e)
//	{
//		std::cerr << e.what() << std::endl;
//		return 1;
//	}
//
//	std::cout << a << std::endl;

	Bureaucrat b;

	try
	{
		++b;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	std::cout << b << std::endl;

	return 0;
}

void	terminateProgram(void)
{
	std::cerr << "Cannot catch an error" << std::endl;
	exit(1);
}
