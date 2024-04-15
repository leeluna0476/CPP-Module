#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	public:
		class	GradeTooHighException : public std::exception
		{
			public:
				const char*	what(void) const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				const char*	what(void) const throw();
		};

		Form(void);
		Form(const std::string& name, const int grade_to_sign, const int grade_to_exec) \
			throw(GradeTooHighException, GradeTooLowException);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form(void);

		const std::string&	getName(void) const;
		const bool&			getSign(void) const;
		const int&			getGradeToSign(void) const;
		const int&			getGradeToExec(void) const;

		bool	beSigned(const Bureaucrat& bureaucrat) \
			throw(GradeTooLowException);

	private:
		const std::string	name;
		bool				sign;
		const int			grade_to_sign;
		const int			grade_to_exec;
};

std::ostream&	operator<<(std::ostream& os, const Form& f);

#endif
