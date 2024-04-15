#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy", 72, 45), target_name("seojilee")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy", 72, 45), target_name(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target_name(other.target_name)
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	AForm::operator=(other);
	target_name = other.target_name;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

// check that the form is signed
// check that the grade of the bureaucrat is high enough
// otherwise, throw an appropriate exception
void	RobotomyRequestForm::execute(const Bureaucrat& executor) const \
			throw(FormNotSigned, GradeTooLowException)
{
	if (sign == false)
		throw FormNotSigned();
	else if (executor.getGrade() > grade_to_exec)
		throw GradeTooLowException();

	drillNoise();
	informRobotomized();
}

void	RobotomyRequestForm::drillNoise(void) const
{
	std::cout << "Whirrrrr... clank, clank, clank... Whirrrrr... clank, clank, clank..." << std::endl;
}

void	RobotomyRequestForm::informRobotomized(void) const
{
	std::cout << "The " << target_name << " has been robotomized successfully 50% of the time" << std::endl;
}
