#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

template <typename Container>
static void printContainer(const Container &c)
{
    typename Container::const_iterator   it = c.begin();
    typename Container::const_iterator   ite = c.end();

    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

int	main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cerr << "Please enter arguments" << std::endl;
        return 1;
    }

    std::stringstream   ss;
    std::vector<int>    vec;
    std::deque<int>     deq;
    for (int i = 1; i < ac; ++i)
    {
        int num;
        ss.clear();
        ss.str(av[i]);
        ss >> num;
        if (ss.fail() || num <= 0)
        {
            std::cerr << "Please enter valid arguments: positive integers" << std::endl;
            return 1;
        }

        vec.push_back(num);
        deq.push_back(num);
    }

    PmergeMe    fj;

    std::cout << "[vector] Before: ";
    printContainer(vec);
    fj.rank(vec);
    std::cout << "[vector] After:  ";
    printContainer(vec);

    std::cout << "[deque]  Before: ";
    printContainer(deq);
    fj.rank(deq);
    std::cout << "[deque]  After:  ";
    printContainer(deq);
}
