#include <iostream>
#include <cstdio>
#include "phonebook.hpp"

int	main(void)
{
	PhoneBook	phbk;
	std::string	cmd;
	int			idx;

	idx = 0;
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
		{
			phbk.add(idx);
			idx = (idx + 1) % 8;
		}
		else if (cmd == "SEARCH")
			phbk.search();
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
