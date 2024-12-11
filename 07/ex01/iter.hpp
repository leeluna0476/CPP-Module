#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	print(T e)
{
	std::cout << e;
}

template <typename T, typename F>
void	iter(T* array, int size, F (*f)(T))
{
	for (int i = 0; i < size; i++)
	{
		f(array[i]);
	}
}

#endif
