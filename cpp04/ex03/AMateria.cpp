#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) {
    this->type = type;
}
    
AMateria::AMateria(const AMateria &original) {
    type = original.type;
}

AMateria& AMateria::operator=(const AMateria &rhs) {
    type = rhs.type;
    return *this;
}

std::string const & AMateria::getType() const {
    return type;
} 

AMateria::~AMateria() {}

void AMateria::use(ICharacter& target) {
    std::cout << "AMateria used on " << target.getName() << std::endl;
}