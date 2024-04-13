#include "Bureaucrat.hpp"
#include <exception>

Bureaucrat::Bureaucrat(void) : name("seojilee"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade) : name(_name)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
	grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		grade = other.grade;

	return *this;
}

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

Bureaucrat&	Bureaucrat::operator++(void)
{
	// add exception handling
	if (grade == 1)
		throw GradeTooHighException();
	--grade;
	return *this;
}

Bureaucrat&	Bureaucrat::operator--(void)
{
	// add exception handling
	if (grade == 150)
		throw GradeTooLowException();
	++grade;
	return *this;
}

void	Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << ": [" << name << "] couldn't sign the form [" << f.getName() << "]" << std::endl;
		return ;
	}

	std::cout << name << " signed " << f.getName() << std::endl;
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Bureaucrat::GradeTooHighException";
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Bureaucrat::GradeTooLowException";
}

std::ostream&	operator <<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	
	return os;
}
