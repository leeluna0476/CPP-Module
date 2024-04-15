#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(void)
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern(void)
{
}

enum FormType	Intern::getFormType(const std::string& name) const throw(NoSuchForm)
{
	const std::string	forms[3] = \
		{ "ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm" };
	
	for (size_t	i = 0; i < 3; i++)
	{
		if (forms[i] == name)
			return (enum FormType)i;
	}

	throw NoSuchForm(name);
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target) const
{
	AForm*	form = NULL;

	switch (getFormType(name))
	{
		case SHRUBBERYCREATION:
			form = new ShrubberyCreationForm(target);
			break;
		case ROBOTOMYREQUEST:
			form = new RobotomyRequestForm(target);
			break;
		case PRESIDENTIALPARDON:
			form = new PresidentialPardonForm(target);
			break;
	}

	std::cout << "Intern creates [" << name << "]" << std::endl;

	return form;
}

Intern::NoSuchForm::NoSuchForm(const std::string& _name) : name(_name)
{
}

Intern::NoSuchForm::~NoSuchForm(void) throw()
{
}

const std::string&	Intern::NoSuchForm::getName(void) const
{
	return name;
}

const char*	Intern::NoSuchForm::what(void) const throw()
{
	return "NoSuchForm";
}
