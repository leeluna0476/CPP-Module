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
	std::cout << "[Ptr]: ";

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
		std::cout << "Cannot identify the type.";
	}
	
	std::cout << std::endl;
}

static void	checkA(Base& p)
{
	A	a = dynamic_cast<A&>(p);
}

static void	checkB(Base& p)
{
	B	b = dynamic_cast<B&>(p);
}

static void	checkC(Base& p)
{
	C	c = dynamic_cast<C&>(p);
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
void	identify(Base& p)
{
	static void	(*checkABC[3])(Base&) = { checkA, checkB, checkC };

	std::cout << "[Ref]: ";
	for (int i = 0; i < 3; i++)
	{
		try
		{
			checkABC[i](p);
			std::cout << "The actual type is <" << "ABC"[i] << ">." << std::endl;
			return ;
		}
		catch (const std::bad_cast& e)
		{
		}
	}

	std::cout << "Cannot identify the type." << std::endl;
}

int	main(void)
{
	Base*	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
	return 0;
}
