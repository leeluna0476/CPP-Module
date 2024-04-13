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

AForm*	Intern::makeForm(const std::string& form_name, const std::string& target) const
{
	AForm*				ret_form = NULL;
	AForm*				form_objects[3] = { new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target) };
	const std::string	form_names[3] = { "ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm" };

//placement new delete
	int	i;
	for (i = 0; i < 3; i++)
	{
		if (form_names[i] == form_name)
			ret_form = form_objects[i];
		else
			delete form_objects[i];
	}

	if (ret_form == NULL)
		throw NoSuchForm(form_name);

	std::cout << "Intern creates [" << ret_form->getName() << "]" << std::endl;

	return ret_form;
}

Intern::NoSuchForm::NoSuchForm(const std::string& _form_name) : form_name(_form_name)
{
}

Intern::NoSuchForm::~NoSuchForm(void) _NOEXCEPT
{
}

const std::string&	Intern::NoSuchForm::getFormName(void) const
{
	return form_name;
}

const char*	Intern::NoSuchForm::what(void) const throw()
{
	return "NoSuchForm";
}
