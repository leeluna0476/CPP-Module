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

    std::cout << mstk.size() << std::endl;
    std::cout << mstk.top() << std::endl;

	return 0;
}
