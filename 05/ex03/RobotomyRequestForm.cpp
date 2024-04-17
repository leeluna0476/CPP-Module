#include "RobotomyRequestForm.hpp"

// @brief Implementation to a class RobotomyRequestForm which inherits an abstract class AForm

/**
 * @brief Default constructor
 *
 * Initializes the name to "Robotomy", the grade to sign to 72, the grade to execute to 45, and the target name to "seojilee"
 * Calls a multi-parameter constructor of AForm to initialize its members.
 */
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy", 72, 45), target_name("seojilee")
{
}

/**
 * @brief Single-parameter constructor
 *
 * Initializes the name to "Robotomy", the grade to sign to 72, the grade to execute to 45, and the target name to target given as a parameter.
 * Calls a multi-parameter constructor of AForm to initialize its members.
 *
 * @param target name of the target of the form
 */
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy", 72, 45), target_name(target)
{
}

/**
 * @brief Copy constructor
 *
 * Copies another RobotomyRequestForm object at construction.
 * Calls a copy constructor of AForm to copy its members.
 *
 * @param other the target of the copy
 */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target_name(other.target_name)
{
}

/**
 * @brief Copy assignment operator
 *
 * Copies another RobotomyRequestForm object after construction.
 * Calls a copy assignment operator of AForm to copy its members.
 *
 * @param other the target of the copy
 */
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	AForm::operator=(other);
	target_name = other.target_name;
	return *this;
}

/**
 * @brief Destructor
 */
RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

/**
 * @brief A function that executes the form
 *
 * Overrided from AForm::execute().
 * Robotomizes the target.
 * Checks the form is signed.
 * Checks the grade of the bureaucrat given as a parameter is high enough to execute the form.
 * Otherwise, throws an appropriate exception.
 *
 * @param executor A bureaucrat that tries to execute the form
 */
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

/**
 * @brief A function that makes a drilling noise
 */
void	RobotomyRequestForm::drillNoise(void) const
{
	std::cout << "Whirrrrr... clank, clank, clank... Whirrrrr... clank, clank, clank..." << std::endl;
}

/**
 * @brief A function that informs successful robotization of the target
 */
void	RobotomyRequestForm::informRobotomized(void) const
{
	std::cout << "The " << target_name << " has been robotomized successfully 50% of the time" << std::endl;
}
