#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "Created new MateriaSource" << std::endl;
    for (int i = 0; i < 4; i++) {
        source[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& original) {
    std::cout << "Copied MateriaSource" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (original.getMateria(i) != NULL)
            source[i] = original.getMateria(i)->clone();
        else (source[i] = NULL);
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
    std::cout << "Equaled MateriaSource" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (source[i] != NULL) delete source[i];
    }
    for (int i = 0; i < 4; i++) {
        if (rhs.getMateria(i) != NULL)
            source[i] = rhs.getMateria(i)->clone();
        else (source[i] = NULL);
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "Deleted MateriaSource" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (source[i] != NULL) delete source[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    std::cout << "Learned materia " << m->getType() << std::endl;
    for (int i = 0; i < 4; i++) {
        if (source[i] == NULL) {
            source[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    std::cout << "Created new materia " << type << std::endl;
    for (int i = 0; i < 4; i++) {
        if (source[i] != NULL && source[i]->getType() == type) {
            return source[i]->clone();
        }
    }
    return NULL;
}

AMateria *MateriaSource::getMateria(int idx) const {
    if (idx < 0 || idx > 3) return NULL;
    return source[idx];
}