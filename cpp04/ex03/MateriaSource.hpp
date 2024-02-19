#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:
        AMateria* source[4];

        MateriaSource();
        MateriaSource(const MateriaSource& original);
        MateriaSource& operator=(const MateriaSource& rhs);
        ~MateriaSource();
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
        AMateria *getMateria(int idx) const;
};

#endif