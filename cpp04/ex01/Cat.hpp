#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{

public:
	Cat( void );
	~Cat( void );
	Cat( const Cat &c);
	Cat &operator=(const Cat &c);
	void makeSound( void ) const;
	void compareCats( const Cat &other);

private:
	Brain *_brain;

};

#endif
