#ifndef TESTCLASS_HPP
# define TESTCLASS_HPP

# include <iostream>

class	TestClass
{
	private:
		int	_data;
	
	public:
		TestClass();
		TestClass(int data);
		TestClass(const TestClass& other);
		TestClass&	operator=(const TestClass& other);
		~TestClass();

		int		getData() const;
		void	setData(int data);
};

std::ostream&	operator<<(std::ostream& os, TestClass& t);

#endif
