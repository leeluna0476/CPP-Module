#include "Bureaucrat.hpp"

/**
 * @brief Default constructor
 *
 * Initializes the name to "seojilee", the grade to 150.
 */
Bureaucrat::Bureaucrat(void) : name("seojilee"), grade(150)
{
}

/**
 * @brief Multi-parameter constructor
 *
 * Initializes the name to _name, the grade to _grade.
 * The grade must not be greater than 1, or lesser than 150.
 * If so, throws either GradeTooHighException or GradeTooLowException.
 *
 * @param _name bureaucrat's name (constant)
 * @param _grade bureaucrat's grade
 */
Bureaucrat::Bureaucrat(const std::string& _name, int _grade) @
		throw(GradeTooHighException, GradeTooLowException) @
		: name(_name)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
	grade = _grade;
}

/**
 * @brief Copy constructor
 *
 * Copies another Bureucrat object at construction.
 *
 * @param the target of the copy
 */
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
}

/**
 * @brief Copy assignment operator overloaded
 *
 * Copies another Bureaucrat object.
 * Does not copy any constants.
 *
 * @param the target of the copy
 */
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		grade = other.grade;

	return *this;
}

/**
 * @brief Destructor
 */
Bureaucrat::~Bureaucrat(void)
{
}

const std::string&	Bureaucrat::getName(void) const
{
	return name;
}

const int&	Bureaucrat::getGrade(void) const
{
	return grade;
}

Bureaucrat&	Bureaucrat::operator++(void) throw(GradeTooHighException)
{
	if (grade == 1)
		throw GradeTooHighException();
	--grade;
	return *this;
}

Bureaucrat&	Bureaucrat::operator--(void) throw(GradeTooLowException)
{
	if (grade == 150)
		throw GradeTooLowException();
	++grade;
	return *this;
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "GradeTooHighException";
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "GradeTooLowException";
}

std::ostream&	operator <<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	
	return os;
}
