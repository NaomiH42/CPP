#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria
{
    protected:

    public:
        Ice(std::string const &type);
        ~Ice();
        Ice(const Ice &original);
        Ice&operator=(const Ice &rhs);
        std::string const & getType() const;
        Ice* clone() const;
}