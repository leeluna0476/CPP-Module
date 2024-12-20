#include "Span.hpp"
#include <exception>
#include <iostream>

int	main(void)
{
    Span    s(10);

    try
    {
        s.addNumber(1);
        s.addNumber(15);
        s.addNumber(7);
        s.addNumber(5);
        s.addNumber(4);

        std::cout << s.shortestSpan() << std::endl;
        std::cout << s.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	return 0;
}
