#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class	Intern
{
	public:
		Intern(void);
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
		~Intern(void);

		AForm*	makeForm(const std::string& form_name, const std::string& target) const;

		class	NoSuchForm : public std::exception
		{
			private:
				std::string	form_name;
			public:
				NoSuchForm(const std::string& _form_name);
				~NoSuchForm(void) _NOEXCEPT;

				const std::string&	getFormName(void) const;
				const char*	what(void) const throw();
		};
};

#endif
