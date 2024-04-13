#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

void	terminateProgram(void);

int	main(void)
{
	std::set_terminate(terminateProgram);

	ShrubberyCreationForm	a("tree");
	Bureaucrat	jisokang("jisokang", 6);
//	Bureaucrat	jisokang("jisokang", 60);
//	Bureaucrat	jisokang("jisokang", 100);

	jisokang.signForm(a);
	jisokang.executeForm(a);

	RobotomyRequestForm	b("robot");
	jisokang.signForm(b);
	jisokang.executeForm(b);
}

void	terminateProgram(void)
{
	std::cerr << "Cannot catch an error" << std::endl;
	exit(1);
}
