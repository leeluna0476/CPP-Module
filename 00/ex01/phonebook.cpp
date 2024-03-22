#include "phonebook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	this->cdx = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add(int idx)
{
	this->contacts[idx].set_first_name(get_input(FIRST_NAME));
	this->contacts[idx].set_last_name(get_input(LAST_NAME));
	this->contacts[idx].set_nickname(get_input(NICKNAME));
	this->contacts[idx].set_phone_number(get_input(PHONE_NUM));
	this->contacts[idx].set_darkest_secret(get_input(SECRET));

	if (this->cdx < 8)
		(this->cdx)++;
}

void	PhoneBook::search(void)
{
	if (this->cdx == 0)
	{
		std::cout << "No database" << std::endl;
		return ;
	}
	std::cout << "Enter an index between 1 ~ " << this->cdx << std::endl;
	print_contacts();
	search_contacts();
}
/*
---------------------------------------------
|     Index|First name| Last name|  Nickname|
---------------------------------------------
*/
