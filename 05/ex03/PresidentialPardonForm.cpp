#include "PresidentialPardonForm.hpp"

// @brief Implementation to a class PresidentialPardonForm which inherits an abstract class AForm

/**
 * @brief Default constructor
 *
 * Initializes the name to "Pardon", the grade to sign to 25, the grade to execute to 5, and the target name to "seojilee"
 * Calls a multi-parameter constructor of AForm to initialize its members.
 */
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Pardon", 25, 5), target_name("seojilee")
{
}

/**
 * @brief Single-parameter constructor
 *
 * Initializes the name to "Pardon", the grade to sign to 25, the grade to execute to 5, and the target name to target given as a parameter.
 * Calls a multi-parameter constructor of AForm to initialize its members.
 *
 * @param target name of the target of the form
 */
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Pardon", 25, 5), target_name(target)
{
}

/**
 * @brief Copy constructor
 *
 * Copies another PresidentialPardonForm object at construction.
 * Calls a copy constructor of AForm to copy its members.
 *
 * @param other the target of the copy
 */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target_name(other.target_name)
{
}

/**
 * @brief Copy assignment operator
 *
 * Copies another PresidentialPardonForm object after construction.
 * Calls a copy assignment operator of AForm to copy its members.
 *
 * @param other the target of the copy
 */
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	AForm::operator=(other);
	target_name = other.target_name;
	return *this;
}

/**
 * @brief Destructor
 */
PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

/**
 * @brief A function that executes the form
 *
 * Overrided from AForm::execute().
 * Informs the target has been pardoned.
 * Checks the form is signed.
 * Checks the grade of the bureaucrat given as a parameter is high enough to execute the form.
 * Otherwise, throws an appropriate exception.
 *
 * @param executor A bureaucrat that tries to execute the form
 */
void	PresidentialPardonForm::execute(const Bureaucrat& executor) const \
			throw(FormNotSigned, GradeTooLowException)
{
	if (sign == false)
		throw FormNotSigned();
	else if (executor.getGrade() > grade_to_exec)
		throw GradeTooLowException();

	informPardoned();
}

/**
 * @brief A function that informs the target has been pardoned
 */
void	PresidentialPardonForm::informPardoned(void) const
{
	std::cout << "The " << target_name << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
