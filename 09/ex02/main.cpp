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

    PmergeMe    fj;

    fj.rank(vec);

//    std::cout << "After:  ";
//    for (std::vector<int>::size_type i = 0; i < vec.size(); ++i)
//    {
//        std::cout << vec[i] << " ";
//    }
//    std::cout << std::endl;
}
