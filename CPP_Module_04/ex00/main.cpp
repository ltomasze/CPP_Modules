/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:14:24 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/15 17:32:33 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
delete meta;
delete j;
delete i;
const WrongAnimal* wrongMeta = new WrongAnimal();
const WrongAnimal* wrongCat = new WrongCat();
std::cout << wrongCat->getType() << " " << std::endl;
wrongCat->makeSound();
wrongMeta->makeSound();
delete wrongMeta;
delete wrongCat;
return 0;
}
