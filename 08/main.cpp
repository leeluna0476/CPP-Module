#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main(void)
{
    std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    for (int i = 0; i < 10; ++i)
    {
        try
        {
            std::cout << easyfind(v, i) << std::endl;
        }
        catch (const std::exception& e)
        {
//            std::cout << "cannot find" << std::endl;
            std::cout << e.what() << std::endl;
        }
    }


	return 0;
}
