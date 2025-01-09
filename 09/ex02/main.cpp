#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <sys/time.h>
#include <iomanip>

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

#ifndef DEQUE
    std::cout << "[vector] Before: ";
    printContainer(vec);
#else
    std::cout << "[deque]  Before: ";
    printContainer(deq);
#endif

    struct timeval  begin;
    gettimeofday(&begin, NULL);
    fj.rank(vec);
    struct timeval  end;
    gettimeofday(&end, NULL);
    double  time_vec = end.tv_usec - begin.tv_usec;

    gettimeofday(&begin, NULL);
    fj.rank(deq);
    gettimeofday(&end, NULL);
    double  time_deq = end.tv_usec - begin.tv_usec;

#ifndef DEQUE
    std::cout << "[vector] After:  ";
    printContainer(vec);
#else
    std::cout << "[deque]  After:  ";
    printContainer(deq);
#endif

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed << time_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << time_deq << " us" << std::endl;
}
