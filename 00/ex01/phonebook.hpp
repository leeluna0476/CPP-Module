#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "contact.hpp"

# define FIRST_NAME "[First name]: "
# define LAST_NAME "[Last name]: "
# define NICKNAME "[Nickname]: "
# define PHONE_NUM "[Phone number]: "
# define SECRET "[Darkest secret]: "

class PhoneBook
{
	private:
		int		cdx;
		Contact contacts[8];
		// add
		std::string	get_input(std::string msg);
		bool		check_number(std::string str, std::string msg);
		void		print_errmsg(std::string str, std::string msg);
		// search
		std::string	print_data(std::string str);
		void		print_contacts(void);
		void		search_contacts(void);

	public:
		PhoneBook();
		~PhoneBook();
		void		add(int idx);
		void		search(void);
};

#endif
