#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{

public:
	Cat( void );
	~Cat( void );
	Cat( const Cat &c);
	Cat &operator=(const Cat &c);
	void makeSound( void ) const;


private:

};

#endif
