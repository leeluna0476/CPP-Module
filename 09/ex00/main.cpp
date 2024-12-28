#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
    if (ac != 2)
    {
        return 0;
    }

    BitcoinExchange btc;
    std::ifstream   infile;

    try
    {
        infile.open(av[1]);
        std::string line;
        std::getline(infile, line);
        btc.isValidHeader(line);

        while (!std::getline(infile, line).eof())
        {
            if (!line.size())
            {
                continue;
            }

            btc.addDataToList(btc.isValidData(line));
            std::cout << line << std::endl;
        }
    }
    catch (const Error &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	return 0;
}
