#include "MutantStack.hpp"
#include <iostream>
#include <vector>

int	main(void)
{
    MutantStack<int, std::vector<int> >    mstk;

    for (int i = 0; i < 100; ++i)
    {
        mstk.push(i);
    }

    mstk.pop();

    std::cout << "size: " << mstk.size() << std::endl;
    std::cout << "top: " << mstk.top() << std::endl;

    MutantStack<int, std::vector<int> >::iterator   it = mstk.begin();
    MutantStack<int, std::vector<int> >::iterator   ite = mstk.end();

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

	return 0;
}
