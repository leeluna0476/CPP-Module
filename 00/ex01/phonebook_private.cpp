#include "phonebook.hpp"
#include <iomanip>
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

std::string	PhoneBook::get_input(std::string msg)
{
	std::string	str;

	for (;;)
	{
		std::cout << msg;
		getline(std::cin, str);

		if (!std::cin.eof() && !str.empty() && check_number(str, msg))
			break;
		else
		{
			print_errmsg(str, msg);
			std::cin.clear();
			clearerr(stdin);
		}
	}
	return str;
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
		std::cout << std::right << std::setw(10) << i + 1;

		// print First name
		std::cout << '|';
		std::cout << std::right << std::setw(10) << this->contacts[i].get_first_name();

		// print Last name
		std::cout << '|';
		std::cout << std::right << std::setw(10) << this->contacts[i].get_last_name();

		// print Nickname
		std::cout << '|';
		std::cout << std::right << std::setw(10) << this->contacts[i].get_nickname() << '|' << std::endl;

		if (i + 1 == this->cdx)
			std::cout << "---------------------------------------------" << std::endl;
		else
			std::cout << "|-------------------------------------------|" << std::endl;
	}
}

void	PhoneBook::search_contacts(void)
{
	int			idx;
	std::string	str;

	for (;;)
	{
		getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << "  \nEnter a value" << std::endl;
			std::cin.clear();
			clearerr(stdin);
			continue;
		}
		std::istringstream iss(str);
		if (!(iss >> idx) || idx < 1 || idx > this->cdx)
			std::cout << "Enter between 1 ~ " << this->cdx << std::endl;
		else
		{
			std::cout << this->contacts[--idx].get_first_name() << std::endl;
			std::cout << this->contacts[idx].get_last_name() << std::endl;
			std::cout << this->contacts[idx].get_nickname() << std::endl;
			std::cout << this->contacts[idx].get_phone_number() << std::endl;
			std::cout << this->contacts[idx].get_darkest_secret() << std::endl;
			break;
		}
	}
}
