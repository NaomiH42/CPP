#include "Ice.hpp"
 
Ice::Ice() : AMateria("ice") {
    std::cout << "Created new ice materia" << std::endl;

}

Ice::~Ice(){
    std::cout << "Deleted ice" << std::endl;
}

Ice::Ice(const Ice &original) :AMateria(original) {
    type = original.getType();
}

Ice &Ice::operator=(const Ice &rhs) {
    type = rhs.getType();
    return *this;
}

Ice* Ice::clone() const {
    std::cout << "Cloned ice" << std::endl;
    return new Ice();
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}