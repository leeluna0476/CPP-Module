#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		const int	max_contacts;
		int			curr_contact;
		int			saved_contacts;
		Contact		contacts[8];

		// add
		std::string	get_input(const std::string &msg);
		void		print_errmsg(const std::string &str, const bool num_checked);

		// search
		std::string	get_printable_data(const std::string &str);
		void		print_contacts(void);
		void		search_contacts(void);

	public:
		PhoneBook();
		~PhoneBook();
		void		add(void);
		void		search(void);
};

#endif
