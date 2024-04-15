#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	protected:
		const std::string	name;
		bool				sign;
		const int			grade_to_sign;
		const int			grade_to_exec;

	public:
		AForm(void);
		AForm(const std::string& _name, const int _grade_to_sign, const int _grade_to_exec) \
			throw(GradeTooHighException, GradeTooLowException);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm(void);

		// getters for each attribute
		const std::string&	getName(void) const;
		const bool&			getSign(void) const;
		const int&			getGradeToSign(void) const;
		const int&			getGradeToExec(void) const;

		bool	beSigned(const Bureaucrat& bureaucrat) \
			throw(GradeTooLowException);

		virtual void	execute(const Bureaucrat& executor) const \
			throw(FormNotSigned, GradeTooLowException) = 0;

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
		
		class	FormNotSigned : public std::exception
		{
			public:
				const char*	what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& f);

#endif
