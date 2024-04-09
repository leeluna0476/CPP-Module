#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

int main (void)
{
	//	cannot instanciate an abstract class
//	Animal	a;
//	Animal	*ptr = new Animal();

	Animal	*handler = new Dog();
	std::cout << handler->getType() << ": ";
	handler->makeSound();
	delete handler;
}
