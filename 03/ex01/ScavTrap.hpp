#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &scavtrap);
		ScavTrap &operator =(const ScavTrap &scavtrap);
		~ScavTrap(void);

		void	guardGate(void);
};

#endif // !SCAVTRAP_HPP
