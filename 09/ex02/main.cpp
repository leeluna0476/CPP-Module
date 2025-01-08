#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

int	main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cerr << "Please enter arguments" << std::endl;
        return 1;
    }

    std::stringstream   ss;
    std::vector<int>    vec;
    for (int i = 1; i < ac; ++i)
    {
        int num;
        ss.clear();
        ss.str(av[i]);
        ss >> num;
        if (ss.fail())
        {
            std::cerr << "Please enter valid arguments: integers" << std::endl;
            return 1;
        }

        vec.push_back(num);
    }
    std::cout << "Before:  ";
    for (std::vector<int>::size_type i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int>    vec2 = vec;

    PmergeMe    fj;

    fj.rank(vec);

    std::cout << "After:        ";
    for (std::vector<int>::size_type i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::sort(vec2.begin(), vec2.end());
    std::cout << "std::sort():  ";
    for (std::vector<int>::size_type i = 0; i < vec2.size(); ++i)
    {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;
}
