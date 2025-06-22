/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 10:35:33 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/22 10:35:42 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& sourceObj) : AMateria(sourceObj) {}

Cure& Cure::operator=(const Cure& sourceObj) {
    if (this != &sourceObj)
        AMateria::operator=(sourceObj);
    return *this;
}

Cure::~Cure() {}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
