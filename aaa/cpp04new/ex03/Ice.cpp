#include "Ice.hpp"
 
Ice::Ice() : AMateria("ice") {

}

Ice::~Ice(){}

Ice::Ice(const Ice &original) :AMateria(original) {
    type = original.getType();
}

Ice &Ice::operator=(const Ice &rhs) {
    type = rhs.getType();
    return *this;
}

Ice* Ice::clone() const {
    return new Ice();
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}