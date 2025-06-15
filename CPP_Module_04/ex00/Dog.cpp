/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:53:24 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/15 16:54:10 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog has been created!" << std::endl;
}

Dog::Dog(const Dog& sourceObj) : Animal(sourceObj)
{
    type = sourceObj.type;
    std::cout << "Dog has been copied!" << std::endl;
}

Dog& Dog::operator=(const Dog& sourceObj)
{
    if (this != &sourceObj)
    {
        Animal::operator=(sourceObj);
        type = sourceObj.type;
    }
    std::cout << "Dog has been assigned!" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog has been destroyed!" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Hau! Hau!" << std::endl;
}