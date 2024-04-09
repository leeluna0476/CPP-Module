#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal
{
	protected:
		std::string type;
		
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		~WrongAnimal(void);

		void		makeSound(void) const;
		std::string	getType(void) const;
};

#endif // !WRONG_ANIMAL_HPP
