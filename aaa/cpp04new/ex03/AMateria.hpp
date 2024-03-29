#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
    std::string type;
    
    public:
    AMateria(std::string const & type);
    virtual ~AMateria() = 0;
    AMateria(const AMateria &original);
    AMateria &operator=(const AMateria &rhs);

    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif