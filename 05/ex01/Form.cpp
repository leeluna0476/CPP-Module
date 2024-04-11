#include "Form.hpp"

Form::Form(void) : name("seojilee"), sign(false), grade_to_sign(150), grade_to_exec(150)
{
}

Form::Form(const Form& other) : name(other.name), sign(other.sign), grade_to_sign(other.grade_to_sign), grade_to_exec(other.grade_to_exec)
{
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		sign = other.sign;
	return *this;
}

Form::~Form(void)
{
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return "GradeTooHighException";
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return "GradeTooLowException";
}

const std::string&	Form::getName(void) const
{
	return name;
}

const bool&	Form::getSign(void) const
{
	return sign;
}

const int&	Form::getGradeToSign(void) const
{
	return grade_to_sign;
}

const int&	Form::getGradeToExec(void) const
{
	return grade_to_exec;
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > grade_to_sign)
		throw GradeTooLowException();
	sign = true;
}

std::ostream&	operator<<(std::ostream& os, const Form& f)
{
	os << "Form: " << f.getName() << ", " << f.getSign() << ", " << f.getGradeToSign() << ", " << f.getGradeToExec() << ", " << std::endl;
	return os;
}
