#include "AMateria.hpp"

AMateria::AMateria() : type("unknown AMateria") {}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria& sourceObj) : type(sourceObj.type) {}

AMateria& AMateria::operator=(const AMateria& sourceObj)
{
    if (this != &sourceObj)
        type = sourceObj.type;
    return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}
