/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:10:53 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/15 18:15:22 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
	brain = new Brain();
    std::cout << "Cat has been created!" << std::endl;
}

Cat::Cat(const Cat& sourceObj) : Animal(sourceObj)
{
    type = sourceObj.type;
	brain = new Brain(*sourceObj.brain);
    std::cout << "Cat has been copied!" << std::endl;
}

Cat& Cat::operator=(const Cat& sourceObj)
{
    if (this != &sourceObj)
    {
        Animal::operator=(sourceObj);
        type = sourceObj.type;
		if (brain)
			delete brain;
		brain = new Brain(*sourceObj.brain);
    }
    std::cout << "Cat has been assigned!" << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat has been destroyed!" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Miau! Miau!" << std::endl;
}