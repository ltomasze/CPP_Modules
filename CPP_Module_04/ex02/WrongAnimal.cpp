/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:24:46 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/15 17:26:45 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal has been created!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& sourceObj) : type(sourceObj.type)
{
    std::cout << "WrongAnimal has been copied!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& sourceObj)
{
    if (this != &sourceObj)
        type = sourceObj.type;
    std::cout << "WrongAnimal has been assigned!" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal has been destroyed!" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Unknown WrongAnimal sound!" << std::endl;
}