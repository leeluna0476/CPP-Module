#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	this->cdx = 0;
}

void	PhoneBook::add(int idx)
{
	get_input(this->contacts[idx].first_name, FIRST_NAME);
	get_input(this->contacts[idx].last_name, LAST_NAME);
	get_input(this->contacts[idx].nickname, NICKNAME);
	get_input(this->contacts[idx].phone_number, PHONE_NUM);
	get_input(this->contacts[idx].darkest_secret, SECRET);
	if (this->cdx < 8)
		(this->cdx)++;
}

void	PhoneBook::search_contacts(void)
{
}

void	PhoneBook::search(void)
{
	print_contacts();
	search_contacts();
}
/*
---------------------------------------------
|     Index|First name| Last name|  Nickname|
---------------------------------------------
*/
