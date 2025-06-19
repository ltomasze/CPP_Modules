#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& sourceObj) : AMateria(sourceObj) {}

Cure& Cure::operator=(const Cure& sourceObj) {
    if (this != &sourceObj)
        AMateria::operator=(sourceObj);
    return *this;
}

Cure::~Cure() {}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
