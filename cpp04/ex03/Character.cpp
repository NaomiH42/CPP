#include "Character.hpp"

Character::~Character() {
    std::cout << "Deleted character " << name << std::endl;
    for (int i = 0; i < 4; i++) {
        if (inventory[i] != NULL) delete inventory[i];
    }
    for (int i = 0; i < 100; i++) {
        if (floor[i] != NULL) delete floor[i];
    }
}

Character::Character(std::string newName) {
    std::cout << "Created new character " << newName << std::endl;
    name = newName;
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
    for (int i = 0; i < 100; i++) {
        floor[i] = NULL;
    }
}

Character::Character(const Character& original) {
    std::cout << "Copied new character " << original.getName() << std::endl;
    name = original.getName();
    for (int i = 0; i < 100; i++) {
        floor[i] = NULL;
    }
    for (int i = 0; i < 4; i++) {
        if (original.getInv(i) != NULL)
            this->inventory[i] = original.getInv(i)->clone();
        else this->inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& rhs) {
    std::cout << "Equaled new character " << rhs.getName() << std::endl;
    name = rhs.getName();
    for (int i = 0; i < 4; i++) {
        if (inventory[i] != NULL) delete inventory[i];
    }
    for (int i = 0; i < 100; i++) {
        if (floor[i] != NULL) delete floor[i];
        floor[i] = NULL;
    }
    for (int i = 0; i < 4; i++) {
        if (rhs.getInv(i) != NULL)
            this->inventory[i] = rhs.getInv(i)->clone();
        else this->inventory[i] = NULL;
    }
    return *this;
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (m == NULL) return;
    std::cout << "Equiped materia " << m->getType() << std::endl;
    for (int i = 0; i < 4; i++) {
        if (inventory[i] == NULL) {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3) {
        std::cout << "invalid index" << std::endl;
        return;
    }
    AMateria *tmp = inventory[idx];
    if (tmp == NULL) return;
    std::cout << "Unequiped materia " << tmp->getType() << " and threw it on the ground" << std::endl;
    for (int i = 0; i < 100; i++) {
        if (floor[i] == NULL) {
            floor[i] = tmp;
            break;
        }
    }
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx > 3 || inventory[idx] == NULL) return;
    inventory[idx]->use(target);
}

AMateria *Character::getInv(int idx) const {
    if (idx < 0 || idx > 3) {
        std::cout << "invalid index" << std::endl;
        return NULL;
    }
    return inventory[idx];
}
