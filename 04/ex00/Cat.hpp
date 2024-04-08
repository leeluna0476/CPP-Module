#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		virtual ~Cat(void);

		virtual void		makeSound(void) const;
		virtual std::string	getType(void) const;
};

#endif // !CAT_HPP
