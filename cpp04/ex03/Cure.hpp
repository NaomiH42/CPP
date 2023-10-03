#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp" 
#include <iostream>

class Cure : public AMateria
{
    protected:

    public:
        Cure(std::string const &type);
        ~Cure();
        Cure(const Cure &original);
        Cure&operator=(const Cure &rhs);
        std::string const & getType() const;
        Cure* clone() const;
}