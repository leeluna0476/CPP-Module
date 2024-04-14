#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Pardon", 25, 5), target_name("seojilee")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Pardon", 25, 5), target_name(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target_name(other.target_name)
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	AForm::operator=(other);
	target_name = other.target_name;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

// check that the form is signed
// check that the grade of the bureaucrat is high enough
// otherwise, throw an appropriate exception
void	PresidentialPardonForm::execute(const Bureaucrat& executor) const \
			throw(FormNotSigned, GradeTooLowException)
{
	if (sign == false)
		throw FormNotSigned();
	else if (executor.getGrade() > grade_to_exec)
		throw GradeTooLowException();

	informPardoned();
}

void	PresidentialPardonForm::informPardoned(void) const
{
	std::cout << "The " << target_name << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
