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

    MutantStack<int, std::vector<int> >::Iterator   it = mstk.begin();
    MutantStack<int, std::vector<int> >::Iterator   ite = mstk.end();

    *(it + 3) = 200;

    while (it != ite)
    {
        std::cout << "iterator: " << *it << std::endl;
        ++it;
    }

	return 0;
}
