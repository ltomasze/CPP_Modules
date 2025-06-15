#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal has been created!" << std::endl;
}

Animal::Animal(const Animal& sourceObj) : type(sourceObj.type)
{
    std::cout << "Animal has been copied!" << std::endl;
}

Animal& Animal::operator=(const Animal& sourceObj)
{
    if (this != &sourceObj)
        type = sourceObj.type;
    std::cout << "Animal has been assigned!" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal has been destroyed!" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout << "Some generic animal sound!" << std::endl;
}
