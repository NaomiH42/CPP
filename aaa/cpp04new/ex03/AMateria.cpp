#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) {
    this.type = type;
}
    
AMateria(const AMateria &original) {
    this.type = original.type;
}

AMateria &operator=(const AMateria &rhs) {
    this.type = rhs.type;
    return *this;
}

std::string const & getType() const {
    return type;
} 

virtual void use(ICharacter& target) {
    
}