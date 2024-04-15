#include "Form.hpp"

Form::Form(void) : \
		name("seojilee"),   \
		sign(false),        \
		grade_to_sign(150), \
		grade_to_exec(150)
{
}

Form::Form(const std::string& _name, const int _grade_to_sign, const int _grade_to_exec) \
		throw(GradeTooHighException, GradeTooLowException) \
		: name(_name),                   \
		sign(false),                   \
		grade_to_sign(_grade_to_sign), \
		grade_to_exec(_grade_to_exec)
{
	if (_grade_to_sign < 1 || _grade_to_exec < 1)
		throw GradeTooHighException();
	else if (_grade_to_sign > 150 || _grade_to_sign > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) : \
		name(other.name),                   \
		sign(other.sign),                   \
		grade_to_sign(other.grade_to_sign), \
		grade_to_exec(other.grade_to_exec)
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
	return "Form::GradeTooHighException";
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return "Form::GradeTooLowException";
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

bool	Form::beSigned(const Bureaucrat& bureaucrat) \
			throw(GradeTooLowException)
{
	bool	ret = sign;

	if (bureaucrat.getGrade() > grade_to_sign)
		throw GradeTooLowException();

	if (sign == false)
		sign = true;
	else
		std::cout << "[" << name << "]: It is already signed" << std::endl;

	return ret;
}

std::ostream&	operator<<(std::ostream& os, const Form& f)
{
	os << "Form: " << f.getName() << ", " << f.getSign() << ", " << f.getGradeToSign() << ", " << f.getGradeToExec() << ", " << std::endl;
	return os;
}
