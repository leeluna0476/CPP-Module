#include <iostream>

void	change_to_uppercase(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		if (msg[i] >= 97 && msg[i] <= 122)
			msg[i] -= 32;
		i++;
	}
}

void	shout(char *msg)
{
	std::cout << msg;
}

int	main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac; i++)
		{
			change_to_uppercase(av[i]);
			shout(av[i]);
		}
		std::cout << std::endl;
	}

	return (0);
}
