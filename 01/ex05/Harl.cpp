#include "Harl.hpp"
#include <iostream>
#include <ostream>

Harl::Harl()
{
	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;

	levels[0] = "Debug";
	levels[1] = "Info";
	levels[2] = "Warning";
	levels[3] = "Error";
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::announce_valid_args(void)
{
	std::cout << "ARGUMENTS: " << std::endl;

	for (int i = 0; i < 4; i++)
		std::cout << levels[i] << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i;

	for (i = 0; i < 4; i++)
	{
		if (level == levels[i])
			break;
	}
	i < 4 ? (this->*f[i])() : announce_valid_args();
}
