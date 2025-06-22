/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 10:35:53 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/22 10:35:55 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
