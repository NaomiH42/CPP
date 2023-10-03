#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class AMateria
{
    protected:

    public:
        AMateria(std::string const &type);
        ~AMateria();
        AMateria(const AMateria &original);
        AMateria&operator=(const AMateria &rhs);
}