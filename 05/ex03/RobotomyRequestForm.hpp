#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm(void);

		void	execute(const Bureaucrat& executor) const \
			throw(FormNotSigned, GradeTooLowException);

	private:
		std::string		target_name;

		void	drillNoise(void) const;
		void	informRobotomized(void) const;
};

#endif
