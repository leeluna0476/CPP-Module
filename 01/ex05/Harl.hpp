#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	private:
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);

		void		announce_valid_args(void);

		void		(Harl::*f[4])(void);
		std::string	__levels[4];

	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif
