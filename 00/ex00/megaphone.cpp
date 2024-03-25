#include <iostream>

void	change_to_uppercase(std::string &str)
{
	for (std::string::iterator i = str.begin(); i != str.end(); i++)
		*i = std::toupper(*i);
}

void	shout(std::string str)
{
	std::cout << str;
}

int	main(int ac, char **av)
{
	std::string	str;

	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac; i++)
		{
			str = av[i];
			change_to_uppercase(str);
			shout(str);
		}
		std::cout << std::endl;
	}

	return (0);
}
