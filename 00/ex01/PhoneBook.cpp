#include "PhoneBook.hpp"
#include "manipulator.hpp"
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : max_contacts(8), curr_contact(0), saved_contacts(0)
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::print_errmsg(const std::string &str, const bool num_checked)
{
	if (!std::cin.eof() && !str.empty() && !num_checked)
		std::cout << "Enter a number" << std::endl;
	else
	{
		if (std::cin.eof())
			std::cout << "  \n";
		std::cout << "Enter a value" << std::endl;
	}
}

std::string	PhoneBook::get_input(const std::string &msg)
{
	std::string	str;
	int			num;
	bool		num_checked;

	for (;;)
	{
		std::cout << msg;
		getline(std::cin, str);

		std::istringstream iss(str);
		num_checked = msg == "[Phone number]: " ? ((iss >> num) && iss.eof()) : true;

		if (!std::cin.eof() && !str.empty() && num_checked)
			break;
		else
		{
			print_errmsg(str, num_checked);
			std::cin.clear();
			clearerr(stdin);
		}
	}
	return str;
}

std::string	PhoneBook::get_printable_data(const std::string &str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

void	PhoneBook::print_contacts(void)
{
	std::string	line;

	std::cout << "---------------------------------------------\n";
	std::cout << "|     Index|First name| Last name|  Nickname|\n";
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < saved_contacts; i++)
	{
		// print Index
		std::cout << '|' << align_width << i + 1;

		// print First name
		std::cout << '|' << align_width << get_printable_data(contacts[i].get_first_name());

		// print Last name
		std::cout << '|' << align_width << get_printable_data(contacts[i].get_last_name());

		// print Nickname
		std::cout << '|' << align_width << get_printable_data(contacts[i].get_nickname()) << '|' << std::endl;

		line = std::string(45, '-');
		if (i + 1 != saved_contacts)
		{
			*(line.begin()) = '|';
			*(line.end() - 1) = '|';
		}
		std::cout << line << std::endl;
	}
}

// << operator overload
void	PhoneBook::search_contacts(void)
{
	int					idx;
	std::string			str;

	for (;;)
	{
		std::cout << "Enter an index between 1 ~ " << saved_contacts << ": ";
		getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << "  \nEnter a value" << std::endl;
			std::cin.clear();
			clearerr(stdin);
			continue;
		}

		std::istringstream iss(str);

		if (!(iss >> idx) || !iss.eof() || idx < 1 || idx > saved_contacts)
			std::cout << "Enter between 1 ~ " << saved_contacts << std::endl;
		else
		{
			std::cout << "[First name]: " << contacts[--idx].get_first_name() << std::endl;
			std::cout << "[Last name]: " << contacts[idx].get_last_name() << std::endl;
			std::cout << "[Nickname]: " << contacts[idx].get_nickname() << std::endl;
			std::cout << "[Phone number]: " << contacts[idx].get_phone_number() << std::endl;
			std::cout << "[Darkest secret]: " << contacts[idx].get_darkest_secret() << std::endl;
			break;
		}
	}
}

void	PhoneBook::add(void)
{
	std::string			arguments[5];
	const std::string	msg[5] = { "[First name]: ", "[Last name]: ", "[Nickname]: ", "[Phone number]: ", "[Darkest secret]: " };

	for (int i = 0; i < 5; i++)
		arguments[i] = get_input(msg[i]);

	Contact	temp(arguments);
	contacts[curr_contact] = temp;

	if (saved_contacts < max_contacts)
		saved_contacts++;
	curr_contact = (curr_contact + 1) % max_contacts;
}

void	PhoneBook::search(void)
{
	if (saved_contacts == 0)
	{
		std::cout << "No database" << std::endl;
		return;
	}
	print_contacts();
	search_contacts();
}
