#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm(void);

		void	execute(const Bureaucrat& executor) const \
			throw(FormNotSigned, GradeTooLowException);

	private:
		std::string		target_name;

		void	informPardoned(void) const;
};

#endif
