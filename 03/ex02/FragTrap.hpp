#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const FragTrap &other);
		FragTrap(const std::string &name);
		FragTrap &operator =(const FragTrap &other);
		~FragTrap(void);

		void	attack(const std::string &target);
		void	highFiveGuys(void);
};

#endif // !FRAGTRAP_HPP
