#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{

public:
	Animal( void );
	virtual ~Animal( void );
	Animal( const Animal &c);
	Animal &operator=( const Animal &c);
	std::string getType( void ) const;
	virtual void makeSound( void ) const = 0;

protected:
	std::string _type;

};

#endif
