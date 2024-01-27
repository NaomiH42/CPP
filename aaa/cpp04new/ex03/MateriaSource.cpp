#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        source[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& original) {
    for (int i = 0; i < 4; i++) {
        if (original.getMateria(i) != NULL)
            source[i] = original.getMateria(i)->clone();
        else (source[i] = NULL);
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
    for (int i = 0; i < 4; i++) {
        if (rhs.getMateria(i) != NULL)
            source[i] = rhs.getMateria(i)->clone();
        else (source[i] = NULL);
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (source[i] != NULL) delete source[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (source[i] == NULL) {
            source[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
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