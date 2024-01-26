#include "Character.hpp"

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (inventory[i] != NULL) delete inventory[i];
    }
}

Character::Character(std::string newName) {
    name = newName;
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(const Character& original) {
    name = original.getName();
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = original.getInv(i);
    }
}

Character& Character::operator=(const Character& rhs) {
    name = rhs.getName();
    for (int i = 0; i < 4; i++) {
        if (inventory[i] != NULL) delete inventory[i];
    }
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = rhs.getInv(i);
    }
    return *this;
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (inventory[i] == NULL) {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3) return;
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx > 3) return;
    inventory[idx]->use(target);
}

AMateria *Character::getInv(int idx) const {
    if (idx < 0 || idx > 3) return NULL;
    return inventory[idx];
}
