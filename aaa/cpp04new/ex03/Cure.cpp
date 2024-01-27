#include "Cure.hpp"
 
Cure::Cure() : AMateria("cure") {
    std::cout << "Created new cure materia" << std::endl;
}

Cure::~Cure(){
    std::cout << "Deleted cure" << std::endl;
}

Cure::Cure(const Cure &original) : AMateria(original) {
    type = original.getType();
}

Cure &Cure::operator=(const Cure &rhs) {
    type = rhs.getType();
    return *this;
}

Cure* Cure::clone() const {
    std::cout << "Cloned cure" << std::endl;
    return new Cure();
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}