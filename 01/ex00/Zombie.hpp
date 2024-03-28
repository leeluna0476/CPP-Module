#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie
{
	private:
		std::string	__name;

	public:
		Zombie();
		Zombie(const std::string &_name);
		~Zombie();
		void	announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
