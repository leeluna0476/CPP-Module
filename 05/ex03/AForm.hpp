#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
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
		
		class	FormNotSigned : public std::exception
		{
			public:
				const char*	what(void) const throw();
		};

		AForm(void);
		AForm(const std::string& _name, const int _grade_to_sign, const int _grade_to_exec) \
			throw(GradeTooHighException, GradeTooLowException);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm(void);

		const std::string&	getName(void) const;
		const bool&			getSign(void) const;
		const int&			getGradeToSign(void) const;
		const int&			getGradeToExec(void) const;

		bool	beSigned(const Bureaucrat& bureaucrat) \
			throw(GradeTooLowException);

		virtual void	execute(const Bureaucrat& executor) const \
			throw(FormNotSigned, GradeTooLowException) = 0;

	protected:
		const std::string	name;
		bool				sign;
		const int			grade_to_sign;
		const int			grade_to_exec;
};

std::ostream&	operator<<(std::ostream& os, const AForm& f);

#endif
