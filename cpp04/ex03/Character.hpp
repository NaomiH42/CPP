#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    public:
        Character(std::string newName);
        ~Character();
        Character(const Character &original);
        Character&operator=(const Character &rhs);
        std::string const &getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);

    private:
        std::string _name;
        AMateria *_inventory[4];

}

#endif