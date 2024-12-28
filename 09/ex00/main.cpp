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
    std::ifstream   database;
    std::ifstream   input_txt;

    try
    {
        database.open("data.csv");

        input_txt.open(av[1]);
        std::string line;
        std::getline(input_txt, line);
        btc.isValidHeader(line);

        while (!std::getline(input_txt, line).eof())
        {
            if (!line.size())
            {
                continue;
            }

            try
            {
                btc.addDataToList(btc.isValidData(line));
                btc.exchangeBitcoin(database);
            }
            catch (const Error &e)
            {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    input_txt.close();
    database.close();

    return 0;
}
