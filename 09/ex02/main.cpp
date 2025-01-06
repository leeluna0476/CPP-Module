#include "PmergeMe.hpp"

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
    v.push_back(11);
//    v.push_back(12);
//    v.push_back(13);
//    v.push_back(14);
//    v.push_back(15);
//    v.push_back(16);
//    v.push_back(9);

    fj.rank(v);
	return 0;
}
