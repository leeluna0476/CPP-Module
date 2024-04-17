#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// @brief Implementation to a class Intern

/**
 * @brief Default constructor
 */
Intern::Intern(void)
{
}

/**
 * @brief Copy constructor
 *
 * Copies another Intern object at construction.
 *
 * @param other the target of the copy
 */
Intern::Intern(const Intern& other)
{
	(void)other;
}

/**
 * @brief Copy assignment operator
 *
 * Copies another Intern object after construction.
 *
 * @param other the target of the copy
 */
Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

/**
 * @brief Destructor
 */
Intern::~Intern(void)
{
}

/**
 * @brief A getter that returns the type of the form that matches the name given as a parameter
 *
 * If no such form, throws NoSuchForm.
 *
 * @param name A form to generate
 */
enum FormType	Intern::getType(const std::string& name) const throw(NoSuchForm)
{
	const std::string	forms[3] = \
		{ "ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm" };
	
	for (size_t i = 0; i < 3; i++)
	{
		if (forms[i] == name)
			return (enum FormType)i;
	}

	throw NoSuchForm(name);
}

/**
 * @brief A function that returns a form that matches the name given as a parameter
 *
 * The memory is dynamically allocated.
 * The user must delete the returned object after use.
 *
 * @param name A form to generate
 * @param target A target that will be given as a parameter to the form
 */
AForm*	Intern::makeForm(const std::string& name, const std::string& target) const
{
	AForm*	form = NULL;

	switch (getType(name))
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

// @brief Implementation to an exception class Intern::NoSuchForm

/**
 * @brief Default constructor
 *
 * Initializes the name to _name given as a parameter.
 */
Intern::NoSuchForm::NoSuchForm(const std::string& _name) : name(_name)
{
}

/**
 * @brief Destructor
 */
Intern::NoSuchForm::~NoSuchForm(void) throw()
{
}

/**
 * @brief A getter that returns the name
 */
const std::string&	Intern::NoSuchForm::getName(void) const
{
	return name;
}

/**
 * @brief A function that returns NoSuchForm in const c_string
 */
const char*	Intern::NoSuchForm::what(void) const throw()
{
	return "NoSuchForm";
}
