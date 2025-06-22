/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 10:35:11 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/22 10:35:13 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("unknown AMateria") {}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria& sourceObj) : type(sourceObj.type) {}

AMateria& AMateria::operator=(const AMateria& sourceObj)
{
    if (this != &sourceObj)
        type = sourceObj.type;
    return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}
