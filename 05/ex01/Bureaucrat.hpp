#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Form.hpp"

class	Form;

class	Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string& _name, int _grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat(void);

		const std::string&	getName(void) const;
		const int&			getGrade(void) const;

		Bureaucrat&	operator++(void);
		Bureaucrat&	operator--(void);

		void	signForm(Form& f);

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

std::ostream	&operator<<(std::ostream &os, const Bureaucrat& bureaucrat);

#endif
