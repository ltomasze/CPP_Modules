/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:13:31 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/15 13:13:33 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " has been created (default constructor)!" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " has been created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& sourceObj) : ClapTrap(sourceObj)
{
    *this = sourceObj;
    std::cout << "FragTrap " << _name << " has been copied!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& sourceObj)
{
    if (this != &sourceObj)
    {
        ClapTrap::operator=(sourceObj);
        _hitPoints = sourceObj._hitPoints;
        _energyPoints = sourceObj._energyPoints;
        _attackDamage = sourceObj._attackDamage;
    }
    std::cout << "FragTrap " << _name << " has been assigned!" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " has been destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        _energyPoints--;
        std::cout << "FragTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "FragTrap " << _name << " cannot attack due to insufficient hit points or energy!" << std::endl;
    }
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}
