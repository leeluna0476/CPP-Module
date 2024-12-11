#include <iostream>
#include <new>

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	try
	{
		_array = new T[n]();
		_size = n;
	}
	catch (const std::bad_alloc& e)
	{
		_array = NULL;
		_size = 0;
		std::cout << e.what();
	}
}

template <typename T>
Array<T>::Array(const Array& other)
{
	try
	{
		_array = new T[other._size];

		for (unsigned int i = 0; i < other._size; i++)
		{
			_array[i] = other._array[i];
		}

		_size = other._size;
	}
	catch (const std::bad_alloc& e)
	{
		_array = NULL;
		_size = 0;
		std::cout << e.what();
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	try
	{
		delete _array;
		_array = new T[other._size];

		for (unsigned int i = 0; i < other._size; i++)
		{
			_array[i] = other._array[i];
		}

		_size = other._size;
	}
	catch (const std::bad_alloc& e)
	{
		_array = NULL;
		_size = 0;
		std::cout << e.what();
	}

	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete _array;
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return _size;
}

template <typename T>
T&	Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
	{
		throw std::out_of_range("index out of range");
	}

	return _array[i];
}
