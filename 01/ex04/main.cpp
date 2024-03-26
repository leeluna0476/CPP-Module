#include <iostream>
#include <fstream>

std::string	sed(std::string &line, const std::string &s1, const std::string &s2)
{
	std::string	substr;
	size_t		line_len;
	size_t		s1_len;
	size_t		s2_len;
	size_t		pos;

	line_len = line.len();
	s1_len = s1.len();
	s2_len = s2.len();
	pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		substr = line.substr(0, pos);
		line = substr + s2 + line[pos];
		pos += s2_len;
	}
	return line;
}

void	replace_str(const std::ofstream &fout, std::string s1, std::string s2)
{
	std::string	line;

	for (;;)
	{
		getline(fout, line);
		line = sed(line, s1, s2);
	}
}

int	main(int ac, char **av)
{
	std::ofstream	fout;
	std::string		filename;
	std::string		s1;
	std::string		s2;

	if (ac != 4)
	{
		std::cerr << "Please give at least three arguments" << std::endl;
		return 1;
	}

	filename = av[1];
	s1 = av[2];
	s2 = av[3];

	fout.open(filename);

	fout.close();
}
