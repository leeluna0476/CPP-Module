#include "BitcoinExchange.hpp"
#include <iostream>

int	main(void)
{
    BitcoinExchange btc;

    try
    {
        btc.isValidHeader("date  value");
//        btc.parseLine(" | data");
    }
    catch (const Error &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

	return 0;
}
