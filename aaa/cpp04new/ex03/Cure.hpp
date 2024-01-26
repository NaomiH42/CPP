#pragma once

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        ~Cure();
        Cure(const Cure &original);
        Cure &operator=(const Cure &rhs);

        Cure* clone() const;
        void use(ICharacter& target);
};