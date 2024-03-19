#include <iostream>
#include "phonebook.hpp"

void	PhoneBook::add(int idx)
{
	this->contacts[idx].idx = idx;
//	std::cout << this->contacts[idx].idx << std::endl;
	

}
