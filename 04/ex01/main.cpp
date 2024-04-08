#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <ostream>

int main (void)
{
	Animal*	a[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			a[i] = new Dog();
		else
			a[i] = new Cat();

		std::cout << a[i]->getType() << std::endl << std::endl;
//		system("leaks -q fire");
	}

	for (int i = 0; i < 10; i++)
	{
		delete a[i];
	}
}
