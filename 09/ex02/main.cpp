#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>

int	main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cerr << "Please enter arguments" << std::endl;
        return 1;
    }

    std::stringstream   ss;
    std::vector<int>    vec;
    std::cout << "Before: ";
    for (int i = 1; i < ac; ++i)
    {
        int num;
        ss.clear();
        ss.str(av[i]);
        ss >> num;
        std::cout << num << " ";
        vec.push_back(num);
    }
    std::cout << std::endl;

    PmergeMe    fj;

    fj.rank(vec);

    std::cout << "After:  ";
    for (int i = 0; i < ac - 1; ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
