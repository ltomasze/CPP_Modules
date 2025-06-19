#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
IMateriaSource* src = new MateriaSource();
//src->learnMateria(new Ice());
AMateria* materiaIce = new Ice();
src->learnMateria(materiaIce);
delete materiaIce;
//src->learnMateria(new Cure());
AMateria* materiaCure = new Cure();
src->learnMateria(materiaCure);
delete materiaCure;

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
