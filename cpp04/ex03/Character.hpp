#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];
        AMateria *floor[100];

    public:
        ~Character();
        Character(std::string newName);
        Character(const Character& original);
        Character&operator=(const Character& rhs);
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        AMateria *getInv(int idx) const;
};

#endif