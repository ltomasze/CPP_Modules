#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name; //own name

    public:
        DiamondTrap();
        DiamondTrap(const std::string& name);
        DiamondTrap(const DiamondTrap& sourceObj);
        DiamondTrap& operator=(const DiamondTrap& sourceObj);
        ~DiamondTrap();

        void whoAmI();
        void attack(const std::string& target); // use ScavTrap::attack
};

#endif
