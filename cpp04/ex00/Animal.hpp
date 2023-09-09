#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{

public:
	Animal( void );
	~Animal( void );
	Animal( const Animal &c);
	Animal &operator=( const Animal &c);
	std::string getType( void ) const;
	virtual void makeSound( void ) const;

protected:
	std::string _type;

};

#endif
