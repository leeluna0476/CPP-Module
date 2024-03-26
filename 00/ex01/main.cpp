#include <iostream>
#include <cstdio>
#include <unistd.h>
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;

	if (!isatty(0))
	{
		std::cerr << "GUESS YOU ARE ATTEMPTING TO GIVE AN INPUT THROUGH A NON-TTY FILE! MERONG!" << std::endl;
		return 1;
	}

	for (;;)
	{
		std::cout << ">>> ";
		getline(std::cin, cmd);
		if (std::cin.eof())
		{
			std::cin.clear();
			clearerr(stdin);
			std::cout << "  \nEnter EXIT if want to exit" << std::endl;
			continue;
		}
		if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
		else if (cmd == "EXIT")
			break;
		else
		{
			if (cmd.empty() == 0)
				std::cout << "Enter one of the followings:\n  ADD\n  SEARCH\n  EXIT" << std::endl;
		}
	}

	return 0;
}
