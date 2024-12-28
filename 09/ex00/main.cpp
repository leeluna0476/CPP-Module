#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Please give a filename." << std::endl;
        return 0;
    }

    BitcoinExchange btc;
    std::ifstream   database;
    std::ifstream   input_txt;

    try
    {
        database.open("data.csv");
        if (!database.is_open())
        {
            std::cerr << "Cannot open file: data.csv" << std::endl;
            return 0;
        }

        input_txt.open(av[1]);
        if (!input_txt.is_open())
        {
            std::cerr << "Cannot open file: " << av[1] << std::endl;
            return 0;
        }

        std::string line;
        std::getline(input_txt, line);
        btc.isValidHeader(line);

        while (std::getline(input_txt, line))
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
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    input_txt.close();
    database.close();

    return 0;
}
