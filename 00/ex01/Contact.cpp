#include "Contact.hpp"
#include <sstream>

Contact::Contact(void)
{
}

Contact::Contact(std::string arguments[5])
{
	first_name = arguments[0];
	last_name = arguments[1];
	nickname = arguments[2];
	phone_number = arguments[3];
	darkest_secret = arguments[4];
}

Contact::~Contact()
{
}

// getter
std::string	Contact::get_first_name()
{
	return this->first_name;
}

std::string	Contact::get_last_name()
{
	return this->last_name;
}

std::string	Contact::get_nickname()
{
	return this->nickname;
}

std::string	Contact::get_phone_number()
{
	return this->phone_number;
}

std::string	Contact::get_darkest_secret()
{
	return this->darkest_secret;
}
