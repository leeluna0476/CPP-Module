#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>
#include <iostream>
#include <cstdlib>
#include <time.h>

// It randomly instanciates A, B or C and returns the instance as a Base pointer.
Base*	generate()
{
	std::srand(time(NULL));
	int	random_value = std::rand() % 3;

	Base*	ret = NULL;
	switch (random_value)
	{
		case 0:
			ret = new A();
			break;
		case 1:
			ret = new B();
			break;
		case 2:
			ret = new C();
			break;
	}

	return ret;
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "The actual type is <A>.";
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "The actual type is <B>.";
	}
	else if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "The actual type is <C>.";
	}
	else
	{
		std::cout << "The actual type is not any of { A, B, C }.";
	}
	
	std::cout << std::endl;
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
void	identify(Base& p)
{
	A	a;
	B	b;
	C	c;

	int i = 0;
	for (; i < 3; i++)
	{
		try
		{
			switch (i)
			{
				case 0:
					a = dynamic_cast<A&>(p);
					break;
				case 1:
					b = dynamic_cast<B&>(p);
					break;
				case 2:
					c = dynamic_cast<C&>(p);
					break;
			}
			break;
		}
		catch (const std::bad_cast& e)
		{
		}
	}
	
	if (i == 3)
	{
		std::cout << "The actual type is not any of { A, B, C }.";
	}
	else
	{
		std::cout << "The actual type is <" << "ABC"[i] << ">.";
	}

	std::cout << std::endl;
}

int	main(void)
{
	Base*	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
	return 0;
}
