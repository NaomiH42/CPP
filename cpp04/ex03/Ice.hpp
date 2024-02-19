#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        ~Ice();
        Ice(const Ice &original);
        Ice &operator=(const Ice &rhs);

        Ice* clone() const;
        void use(ICharacter& target);
};

#endif