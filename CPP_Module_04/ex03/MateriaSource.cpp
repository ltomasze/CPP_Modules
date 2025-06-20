#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        _templates[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& sourceObj)
{
    for (int i = 0; i < 4; ++i) {
        if (sourceObj._templates[i])
            _templates[i] = sourceObj._templates[i]->clone();
        else
            _templates[i] = 0;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& sourceObj)
{
    if (this != &sourceObj) {
        for (int i = 0; i < 4; ++i) {
            if (_templates[i])
                delete _templates[i];
            if (sourceObj._templates[i])
                _templates[i] = sourceObj._templates[i]->clone();
            else
                _templates[i] = 0;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        if (_templates[i])
            delete _templates[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; ++i) {
        if (!_templates[i])
        {
            _templates[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i) {
        if (_templates[i] && _templates[i]->getType() == type)
            return _templates[i]->clone();
    }
    return 0;
}
