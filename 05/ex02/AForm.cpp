#include "AForm.hpp"

AForm::AForm(void) : \
		name("seojilee"),   \
		sign(false),        \
		grade_to_sign(150), \
		grade_to_exec(150)
{
}

AForm::AForm(const std::string& _name, const int _grade_to_sign, const int _grade_to_exec) : \
		name(_name),              \
		sign(false),                   \
		grade_to_sign(_grade_to_sign), \
		grade_to_exec(_grade_to_exec)
{
	if (_grade_to_sign < 1 || _grade_to_exec < 1)
		throw GradeTooHighException();
	else if (_grade_to_sign > 150 || _grade_to_sign > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : \
		name(other.name),                   \
		sign(other.sign),                   \
		grade_to_sign(other.grade_to_sign), \
		grade_to_exec(other.grade_to_exec)
{
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		sign = other.sign;
	return *this;
}

AForm::~AForm(void)
{
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return "AForm::GradeTooHighException";
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return "AForm::GradeTooLowException";
}

const char*	AForm::FormNotSigned::what(void) const throw()
{
	return "AForm::FormNotSigned";
}

const std::string&	AForm::getName(void) const
{
	return name;
}

const bool&	AForm::getSign(void) const
{
	return sign;
}

const int&	AForm::getGradeToSign(void) const
{
	return grade_to_sign;
}

const int&	AForm::getGradeToExec(void) const
{
	return grade_to_exec;
}

bool	AForm::beSigned(const Bureaucrat& bureaucrat)
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

std::ostream&	operator<<(std::ostream& os, const AForm& f)
{
	os << "AForm: " << f.getName() << ", " << f.getSign() << ", " << f.getGradeToSign() << ", " << f.getGradeToExec() << ", " << std::endl;

	return os;
}
