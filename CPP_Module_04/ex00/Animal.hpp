#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        Animal(const Animal& sourceObj);
        Animal& operator=(const Animal& sourceObj);
        virtual ~Animal();

        std::string getType() const;
        virtual void makeSound() const;
};

#endif
