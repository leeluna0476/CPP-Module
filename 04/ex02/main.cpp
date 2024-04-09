#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>
#include <ostream>

int main (void)
{
//	cannot instanciate an abstract class
//	Animal	a;
//	Animal	*ptr = new Animal();

	Animal	*uptr = new Dog();
	std::cout << uptr->getType() << ": ";
	uptr->makeSound();
	delete uptr;
}
