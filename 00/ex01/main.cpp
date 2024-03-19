#include <iostream>
#include "phonebook.hpp"

int	main(void)
{
	PhoneBook		phbk;
	std::string		cmd;
	int				idx;

	idx = 0;
	for (;;)
	{
		std::cin >> cmd;
		if (std::cin.fail() || std::cin.eof() || cmd == "EXIT")
			break ;
		else if (cmd == "ADD")
		{
			phbk.add(idx);
			idx = (idx + 1) % 8;
		}
		else
			std::cerr << "Please enter a valid command." << std::endl;
	}

	return (0);
}
