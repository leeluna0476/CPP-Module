#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class	Form
{
	private:
		const std::string	name;
		bool				sign;
		const int			grade_to_sign;
		const int			grade_to_exec;

	public:
		// occf
		Form(void);
		Form(const std::string& name, const int grade_to_sign, const int grade_to_exec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form(void);

		// getters for each attribute
		const std::string&	getName(void) const;
		const bool&			getSign(void) const;
		const int&			getGradeToSign(void) const;
		const int&			getGradeToExec(void) const;

		void	beSigned(const Bureaucrat& b);

		// exception classes
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
};

std::ostream&	operator<<(std::ostream& os, const Form& f);

#endif
