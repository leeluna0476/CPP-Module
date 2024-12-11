#include "iter.hpp"
#include <iostream>
#include <cstring>
#include "TestClass.hpp"

int	main(void)
{
	int	i_array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	void	(*i_print)(int) = print<int>;
	iter(i_array, sizeof(i_array) / sizeof(int), i_print);

	std::cout << std::endl;

	const char*	str = "Hello world";
	void	(*c_print)(char) = print<char>;
	iter(const_cast<char*>(str), std::strlen(str), c_print);

	std::cout << std::endl;

	TestClass*	tc_array = new TestClass[10];
	for (int i = 0; i < 10; i++)
	{
		tc_array[i].setData(i);
	}
	void	(*tc_print)(TestClass) = print<TestClass>;
	iter(tc_array, 10, tc_print);

	std::cout << std::endl;

	delete[] tc_array;

	return 0;
}
