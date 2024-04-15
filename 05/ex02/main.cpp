#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>

void	terminateProgram(void);

int	main(void)
{
	std::set_terminate(terminateProgram);

//	ShrubberyCreationForm	a("tree");
	Bureaucrat	jisokang("jisokang", 1);
//	Bureaucrat	jisokang("jisokang", 6);
//	Bureaucrat	jisokang("jisokang", 60);
//	Bureaucrat	jisokang("jisokang", 100);

//	jisokang.signForm(a);
//	jisokang.executeForm(a);

	RobotomyRequestForm	b("cadet");
	jisokang.signForm(b);
	jisokang.executeForm(b);

	PresidentialPardonForm	c("prisoner");
	jisokang.signForm(c);
	jisokang.executeForm(c);
}

void	terminateProgram(void)
{
	std::cerr << "Cannot catch an error" << std::endl;
	exit(1);
}
