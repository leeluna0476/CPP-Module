#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class	ShrubberyCreationForm : public AForm
{
	private:
		mutable std::ofstream	target_file;
		std::string				target_name;

		void	drawASCIITree(void) const;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm(void);

		void	execute(const Bureaucrat& executor) const;
};

#endif
