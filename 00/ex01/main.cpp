#include <iostream>
#include "phonebook.hpp"

int	main(void)
{
	PhoneBook		phbk;
	std::string		cmd;

	for (;;)
	{
		std::cin >> cmd;
		if (cmd == "ADD")
			phbk.add();
		else if (cmd == "EXIT")
			break ;
		else
			std::cerr << "Please enter a valid command." << std::endl;
	}

	return (0);
}
