#include "Character.hpp"

Character::Character(std::string newName) : _name(newName)
{
    std::cout << "A new hero " 
        << name << " has spawned!" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::~Character()
{
    std::cout << "Hero " << _name << " has died." << std::endl;
    for (int i = 0; i < 4, i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
}

Character::Character(const Character &original)
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
        if (original._inventory[i])
            _inventory[i] = original._inventory[i];
    }
    _name = original._name;
}

Character &Character::operator=(const Character &rhs)
{
    if (this != *rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
                delete _inventory[i];
            if (original._inventory[i])
                _inventory[i] = original._inventory[i];
        }
        _name = original._name;
    }
    return this;
}

std::string const &Character::getName() const
{
    return (_name);
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!(this->_inventory[i]))
        {
            _inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        return ;
    this->_inventory[idx] = NULL;
}