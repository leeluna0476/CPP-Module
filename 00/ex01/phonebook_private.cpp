#include "phonebook.hpp"
#include <iostream>
#include <sstream>

bool	PhoneBook::check_number(std::string str, std::string msg)
{
	int	num;

	std::istringstream iss(str);
	return msg == PHONE_NUM ? iss >> num : true;
}

void	PhoneBook::print_errmsg(std::string str, std::string msg)
{
	if (!std::cin.eof() && !str.empty() && !check_number(str, msg))
		std::cout << "Enter a number" << std::endl;
	else
	{
		if (std::cin.eof())
			std::cout << "  \n";
		std::cout << "Enter a value" << std::endl;
	}
}

void	PhoneBook::get_input(std::string &str, std::string msg)
{
	while (42)
	{
		std::cout << msg;
		getline(std::cin, str);

		if (!std::cin.eof() && !str.empty() && check_number(str, msg))
			break ;
		else
		{
			print_errmsg(str, msg);
			std::cin.clear();
			clearerr(stdin);
		}
	}
}

void	PhoneBook::print_contacts(void)
{
	std::cout << "---------------------------------------------\n";
	std::cout << "|     Index|First name| Last name|  Nickname|\n";
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < this->cdx; i++)
	{
		// print Index
		std::cout << '|';
		std::cout.width(10);
		std::cout << std::right << i + 1;

		// print First name
		std::cout << '|';
		std::cout.width(10);
		std::cout << std::right << this->contacts[i].first_name;

		// print Last name
		std::cout << '|';
		std::cout.width(10);
		std::cout << std::right << this->contacts[i].last_name;

		// print Nickname
		std::cout << '|';
		std::cout.width(10);
		std::cout << std::right << this->contacts[i].nickname << '|' << std::endl;

		if (i + 1 == this->cdx)
			std::cout << "---------------------------------------------" << std::endl;
		else
			std::cout << "|-------------------------------------------|" << std::endl;
	}
}
