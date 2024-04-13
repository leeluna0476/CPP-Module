#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

void	terminateProgram(void);

int	main(void)
{
	std::set_terminate(terminateProgram);

	ShrubberyCreationForm	a("tree");
	Bureaucrat	jisokang("jisokang", 1);

	jisokang.signForm(a);
	jisokang.executeForm(a);
}

void	terminateProgram(void)
{
	std::cerr << "Cannot catch an error" << std::endl;
	exit(1);
}
