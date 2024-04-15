#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class	Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	
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
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
