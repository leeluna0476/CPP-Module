#include "MutantStack.hpp"
#include <iostream>
#include <vector>

int	main(void)
{
    MutantStack<int>    mstk;

    for (int i = 0; i < 100; ++i)
    {
        mstk.push(i);
    }

    mstk.pop();

    std::cout << "size: " << mstk.size() << std::endl;
    std::cout << "top: " << mstk.top() << std::endl;

    MutantStack<int>::iterator   it = mstk.begin();
    MutantStack<int>::iterator   ite = mstk.end();

    *(it + 3) = 200;
    it += 3;
    *(it - 3) = 100;
    it -= 3;

    if (*it < *(it + 3))
    {
        std::cout << *it << " " << *(it + 3) << std::endl;
    }

    while (it != ite)
    {
        std::cout << "iterator: " << *(it++) << std::endl;
    }

    std::cout << "\n\n===================================\n\n" << std::endl;

    MutantStack<int>    mstk2 = mstk;
    it = mstk2.begin();
    ite = mstk2.end();

    while (it != ite)
    {
        std::cout << "iterator: " << *(it++) << std::endl;
    }

    std::cout << "\n\n===================================\n\n" << std::endl;

    MutantStack<int>    mstk3;

    mstk3 = mstk2;
    it = mstk2.begin();
    ite = mstk2.end();

    while (it != ite)
    {
        std::cout << "iterator: " << *(it++) << std::endl;
    }

    std::cout << "\n\n===================================\n\n" << std::endl;

    const MutantStack<int>  cmstk = mstk;
    MutantStack<int>::const_iterator   cit = cmstk.begin();
    MutantStack<int>::const_iterator   cite = cmstk.end();

    while (cit != cite)
    {
        std::cout << "const_iterator: " << *(cit++) << std::endl;
    }

	return 0;
}
