#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hit;
		unsigned int	_energy;
		unsigned int	_attack;
		
	public:
		ClapTrap();
		ClapTrap(const ClapTrap &claptrap);
		ClapTrap(const std::string &_name);
		ClapTrap &operator =(const ClapTrap &claptrap);
		~ClapTrap();

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
		unsigned int	getAttackValue(void) const;
};

#endif
