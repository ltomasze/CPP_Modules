#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* _templates[4];
public:
    MateriaSource();
    MateriaSource(const MateriaSource& sourceObj);
    MateriaSource& operator=(const MateriaSource& sourceObj);
    virtual ~MateriaSource();

    virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(std::string const & type);
};

#endif
