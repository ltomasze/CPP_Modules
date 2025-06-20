#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& sourceObj) : AMateria(sourceObj) {}

Ice& Ice::operator=(const Ice& sourceObj)
{
    if (this != &sourceObj)
        AMateria::operator=(sourceObj);
    return *this;
}

Ice::~Ice() {}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
