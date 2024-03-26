#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		std::string	get_input(const std::string &msg);

	// remove getter, setter
	// add constructor
	public:
		Contact();
		Contact(std::string arguments[5]);
		~Contact();
		// getter
		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nickname();
		std::string	get_phone_number();
		std::string	get_darkest_secret();

		void	print_errmsg(const std::string &str, const bool num_checked);
};

#endif
