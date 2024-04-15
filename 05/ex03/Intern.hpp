#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <exception>
# include "AForm.hpp"

enum	FormType
{
	SHRUBBERYCREATION = 0,
	ROBOTOMYREQUEST,
	PRESIDENTIALPARDON
};

class	Intern
{
	public:
		class	NoSuchForm : public std::exception
		{
			private:
				std::string name;

			public:
				NoSuchForm(const std::string& _name);
				~NoSuchForm(void) throw();

				const std::string&	getName(void) const;
				const char*	what(void) const throw();
		};

		Intern(void);
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
		~Intern(void);

		AForm*	makeForm(const std::string& name, const std::string& target) const;

	private:
		enum FormType	getType(const std::string& name) const throw(NoSuchForm);
};

#endif
