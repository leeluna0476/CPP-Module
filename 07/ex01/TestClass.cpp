#include "TestClass.hpp"

TestClass::TestClass() : _data(0)
{
}

TestClass::TestClass(int data) : _data(data)
{
}

TestClass::TestClass(const TestClass& other) : _data(other._data)
{
}

TestClass&	TestClass::operator=(const TestClass& other)
{
	_data = other._data;
	return *this;
}

TestClass::~TestClass()
{
}

int	TestClass::getData() const
{
	return _data;
}

void	TestClass::setData(int data)
{
	_data = data;
}

std::ostream&	operator<<(std::ostream& os, TestClass& t)
{
	os << t.getData();
	return os;
}
