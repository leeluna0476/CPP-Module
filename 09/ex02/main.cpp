#include "PmergeMe.hpp"
#include <iostream>

int	main(void)
{
    PmergeMe    fj;

    std::vector<int> v;

    v.push_back(1);
    v.push_back(4);
    v.push_back(7);
    v.push_back(2);
    v.push_back(8);
    v.push_back(3);
    v.push_back(5);
    v.push_back(6);
    v.push_back(10);
    v.push_back(9);
    v.push_back(11);
    v.push_back(12);
    v.push_back(13);
    v.push_back(14);
    v.push_back(15);
    v.push_back(16);
    v.push_back(17);
    v.push_back(18);
    v.push_back(19);
    v.push_back(20);
    v.push_back(21);
    v.push_back(22);
    v.push_back(23);
    v.push_back(24);
    v.push_back(25);
    v.push_back(26);
    v.push_back(27);
    v.push_back(28);
    v.push_back(29);
    v.push_back(30);
    v.push_back(31);
//    v.push_back(32);

    std::cout << "Before: ";
    for (std::vector<int>::size_type i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    fj.rank(v);

    std::cout << "After:  ";
    for (std::vector<int>::size_type i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

	return 0;
}
