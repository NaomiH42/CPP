#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{

public:
	WrongAnimal( void );
	virtual ~WrongAnimal( void );
	WrongAnimal( const WrongAnimal &c);
	WrongAnimal &operator=( const WrongAnimal &c);
	std::string getType( void ) const;
	virtual void makeSound( void ) const;

protected:
	std::string _type;

};

#endif
