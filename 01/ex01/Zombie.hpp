#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie
{
	private:
		std::string	name;

	public:
		Zombie();
		Zombie(const std::string &_name);
		~Zombie();
		void	announce(void);
		void	set_name(const std::string &_name);
};

Zombie *zombieHorde(int N, std::string name);

#endif
