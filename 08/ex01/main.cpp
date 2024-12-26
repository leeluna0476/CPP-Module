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
        s.addNumber(-1);
        s.addNumber(2147483647);
        s.addNumber(-2147483648);

        s.printElements();

        std::cout << s.shortestSpan() << std::endl;
        std::cout << s.longestSpan() << std::endl;

        const Span  cs = s;
        std::vector<int>    v;
        v.push_back(6);
        v.push_back(3);

        s.addRange(v.begin(), v.end());
        
        s.printElements();

    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;

    return 0;
}
