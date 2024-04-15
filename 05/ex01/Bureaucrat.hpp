#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Form.hpp"

class	Form;

class	Bureaucrat
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
		
		Bureaucrat(void);
		Bureaucrat(const std::string& _name, int _grade) \
			throw(GradeTooHighException, GradeTooLowException);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat(void);

		const std::string&	getName(void) const;
		const int&			getGrade(void) const;

		Bureaucrat&	operator++(void) throw(GradeTooHighException);
		Bureaucrat&	operator--(void) throw(GradeTooLowException);

		void	signForm(Form& form);

	private:
		const std::string	name;
		int					grade;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
