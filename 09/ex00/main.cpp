#include "BitcoinExchange.hpp"
#include <iostream>

int	main(void)
{
    BitcoinExchange btc;

    try
    {
        btc.isValidHeader("date|value");
        btc.isValidData("2024-12-31 | 333");
        btc.isValidData("2023-02-28    | 333");
    }
    catch (const Error &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

	return 0;
}
