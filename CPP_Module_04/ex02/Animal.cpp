/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:14:13 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/15 16:59:48 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "AAnimal base part of a derived object has been created!" << std::endl;
}

AAnimal::AAnimal(const AAnimal& sourceObj) : type(sourceObj.type)
{
    std::cout << "AAnimal base part of a derived object has been copied!" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& sourceObj)
{
    if (this != &sourceObj)
        type = sourceObj.type;
    std::cout << "AAnimal base part of a derived object has been assigned!" << std::endl;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal base part of a derived object has been destroyed!" << std::endl;
}

std::string AAnimal::getType() const
{
    return type;
}
