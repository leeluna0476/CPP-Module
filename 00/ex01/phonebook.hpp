#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];

	public:
		void	add(int idx);
		void	search(void);
};

#endif
