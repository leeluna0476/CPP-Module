#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>

void	terminateProgram(void);
//void	leaks(void);

int	main(void)
{
	std::set_terminate(terminateProgram);
//	atexit(leaks);

	try
	{
		Bureaucrat	mypark("mypark", 1);

		Intern	intern;
		AForm*	form1 = intern.makeForm("RobotomyRequestForm", "learner");
		mypark.signForm(*form1);
		mypark.executeForm(*form1);
		delete form1;

		AForm*	form2 = intern.makeForm("SaveSeojileeForm", "learner");
		mypark.signForm(*form2);
		mypark.executeForm(*form2);
		delete form2;
	}
	catch(const Intern::NoSuchForm& e)
	{
		std::cerr << e.what() << ": Intern couldn't create [" << e.getName() << "]" << std::endl;
	}
}

void	terminateProgram(void)
{
	std::cerr << "Cannot catch an error" << std::endl;
	exit(1);
}
//
//void	leaks(void)
//{
//	system("leaks -q intern");
//}
