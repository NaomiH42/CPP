#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{

public:
	Dog( void );
	~Dog( void );
	Dog( const Dog &c);
	Dog &operator=( const Dog &c);
	void makeSound( void ) const;
	void compareDogs( const Dog &other);

private:
	Brain *_brain;

};

#endif
