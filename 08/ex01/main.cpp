#include "Span.hpp"
#include <exception>
#include <iostream>

int	main(void)
{
    Span    s(10);
    Span    sp = Span(5);

    try
    {
        s.addNumber(1);
        s.addNumber(15);
        s.addNumber(7);
        s.addNumber(5);
        s.addNumber(4);

        std::cout << s.shortestSpan() << std::endl;
        std::cout << s.longestSpan() << std::endl;

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;

    return 0;
}
