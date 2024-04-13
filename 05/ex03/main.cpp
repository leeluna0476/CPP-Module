#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>

void	terminateProgram(void);

int	main(void)
{
	std::set_terminate(terminateProgram);

	Bureaucrat	jisokang("jisokang", 1);

	Intern	seojilee;
	std::string	form1 = "RobotomyRequestForm";
	std::string	form2 = "SaveSeoileeForm";

	try
	{
		AForm*	d = seojilee.makeForm(form1, "member");
		AForm*	e = seojilee.makeForm(form2, "nooo");

		jisokang.signForm(*d);
		jisokang.executeForm(*d);
		jisokang.signForm(*e);
		jisokang.executeForm(*e);

		delete d;
		delete e;
	}
	catch (const Intern::NoSuchForm& e)
	{
		std::cout << e.what() << ": The intern couldn't find [" << e.getFormName() << "]" << std::endl;
	}
}

void	terminateProgram(void)
{
	std::cerr << "Cannot catch an error" << std::endl;
	exit(1);
}
