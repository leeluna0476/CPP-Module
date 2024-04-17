#include "Form.hpp"

/**
 * @brief Default constructor
 *
 * Initializes the name to "seojilee", the sign to false, the grades to 150.
 */
Form::Form(void) : \
		name("seojilee"),   \
		sign(false),        \
		grade_to_sign(150), \
		grade_to_exec(150)
{
}

/**
 * @brief Multi-parameter constructor
 *
 * Initializes the name to _name, the grades to each corresponding.
 */
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

/**
 * @brief Copy constructor
 *
 * Copies another Form object at construction.
 *
 * @param other the target of the copy
 */
Form::Form(const Form& other) : \
		name(other.name),                   \
		sign(other.sign),                   \
		grade_to_sign(other.grade_to_sign), \
		grade_to_exec(other.grade_to_exec)
{
}

/**
 * @brief Copy constructor
 *
 * Copies another Form object at construction.
 *
 * @param other the target of the copy
 */
Form& Form::operator=(const Form& other)
{
	if (this != &other)
		sign = other.sign;
	return *this;
}

/**
 * @brief Destructor
 */
Form::~Form(void)
{
}

/**
 * @brief A function that returns GradeTooHighException in const c_string
 */
const char*	Form::GradeTooHighException::what(void) const throw()
{
	return "Form::GradeTooHighException";
}

/**
 * @brief A function that returns GradeTooLowException in const c_string
 */
const char*	Form::GradeTooLowException::what(void) const throw()
{
	return "Form::GradeTooLowException";
}

/**
 * @brief A getter that returns the name
 */
const std::string&	Form::getName(void) const
{
	return name;
}

/**
 * @brief A getter that returns the sign state
 */
const bool&	Form::getSign(void) const
{
	return sign;
}

/**
 * @brief A getter that returns the grade to sign the form
 */
const int&	Form::getGradeToSign(void) const
{
	return grade_to_sign;
}

/**
 * @brief A getter that returns the grade to execute the form
 */
const int&	Form::getGradeToExec(void) const
{
	return grade_to_exec;
}

/**
 * @brief A function that sets itself to be signed
 *
 * If the grade of the bureaucrat is high enough, set the sign state true.
 * If not, throws GradeTooLowException.
 *
 * @param bureaucrat A bureaucrat that tries to sign the form.
 */
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

/**
 * @brief An output operator overloaded to print the attributes of bureaucrat in format
 *
 * @param os A reference to std::cout
 * @param f A form to print out
 */
std::ostream&	operator<<(std::ostream& os, const Form& f)
{
	os << "Form: " << f.getName() << ", " << f.getSign() << ", " << f.getGradeToSign() << ", " << f.getGradeToExec() << ", " << std::endl;
	return os;
}
