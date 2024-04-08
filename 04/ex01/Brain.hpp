#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class	Brain
{
	protected:
		std::string	ideas[100];
	
	public:
		Brain(void);
		Brain(const Brain& other);
		Brain&	operator =(const Brain& other);
		~Brain(void);
};

#endif
