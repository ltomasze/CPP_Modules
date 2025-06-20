#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    return 0;
}
/*
int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* witcher = new Character("Witcher");
    ICharacter* monster = new Character("Monster");

    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");
    witcher->equip(ice);
    witcher->equip(cure);

    std::cout << "Test of using materia:" << std::endl;
    witcher->use(0, *monster);
    witcher->use(1, *monster);
    std::cout << "Test of an empty slot." << std::endl;
    witcher->use(3, *monster);
    std::cout << "Test of unequipping." << std::endl;
    witcher->unequip(1);
    witcher->use(1, *monster);
    std::cout << "Test of copying a character:" << std::endl;
    Character* copy = new Character(*(Character*)witcher);
    copy->use(0, *monster);

    witcher->unequip(0);
    delete ice;
    delete cure;
    delete witcher;
    delete monster;
    delete copy;
    delete src;

    return 0;
}*/
