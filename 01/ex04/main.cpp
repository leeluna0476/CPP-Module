#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

std::string	sed(std::string &line, const std::string &s1, const std::string &s2)
{
	std::string	substr;
	size_t		line_len;
	size_t		s1_len;
	size_t		s2_len;
	size_t		pos;

	s1_len = s1.length();
	s2_len = s2.length();
	pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line_len = line.length();
		substr = line.substr(0, pos);
		line = line.substr(0, pos) + s2 + line.substr(pos + s1_len, line_len);
		pos = substr.length() + s2_len;
	}
	return line;
}

void	replace_str(std::ifstream &fin, std::ofstream &fout, const std::string &s1, const std::string &s2)
{
	std::stringstream	buf;
	std::string			line;

	buf << fin.rdbuf();
	line = buf.str();
	fout << sed(line, s1, s2);
}

int	main(int ac, char **av)
{
	std::ifstream	fin;
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

	fin.open(av[1]);
	if (!fin.is_open())
		return 1;
	fout.open((filename + ".replace").c_str());
	if (!fout.is_open())
	{
		fin.close();
		return 1;
	}

	replace_str(fin, fout, s1, s2);

	fin.close();
	fout.close();
}
