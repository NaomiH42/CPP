#include "Cure.hpp"
 
Cure::Cure() : AMateria("cure") {

}

Cure::~Cure(){}

Cure::Cure(const Cure &original) : AMateria(original) {
    type = original.getType();
}

Cure &Cure::operator=(const Cure &rhs) {
    type = rhs.getType();
    return *this;
}

Cure* Cure::clone() const {
    return new Cure();
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}