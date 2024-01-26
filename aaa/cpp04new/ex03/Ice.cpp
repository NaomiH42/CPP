#include "Ice.hpp"
 
Ice::Ice() : AMateria("ice") {

}

Ice::~Ice(){}

Ice::Ice(const Ice &original) :AMateria(original) {

}

Ice &Ice::operator=(const Ice &rhs) {
}

Ice* Ice::clone() const {
    return new Ice();
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}