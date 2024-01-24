#pragma once

#include <iostream>

class AMateria
{
    protected:
    std::string type;
    
    public:
    AMateria(std::string const & type);
    virtual ~AMateria();
    AMateria(const AMateria &original);
    AMateria &operator=(const AMateria &rhs);

    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};