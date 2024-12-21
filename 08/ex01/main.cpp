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

        s.printElements();

        std::cout << s.shortestSpan() << std::endl;
        std::cout << s.longestSpan() << std::endl;

//        sp.addNumber(6);
//        sp.addNumber(3);
//        sp.addNumber(17);
//        sp.addNumber(9);
//        sp.addNumber(11);
//
//        std::cout << sp.shortestSpan() << std::endl;
//        std::cout << sp.longestSpan() << std::endl;

        std::vector<int>    v;
        v.push_back(6);
        v.push_back(3);
        v.push_back(17);

        s.addRange(v.begin(), v.end());
        
        s.printElements();

//        std::vector<char>    v;
//        v.push_back('a');
//        v.push_back('b');
//        v.push_back('c');
//        s.addRange(v.begin(), v.end());
//        std::cout << s.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;

    return 0;
}
