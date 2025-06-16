/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:14:24 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/15 18:49:23 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const AAnimal* j = new Dog();
const AAnimal* i = new Cat();
//AAnimal* ptr = new AAnimal();
delete j;//should not create a leak
delete i;
std::cout <<"MY TEST!!!"<<std::endl;
const int   numberOfAnimals = 4;
AAnimal *animals[numberOfAnimals];
for (int i = 0; i < numberOfAnimals / 2; ++i)
    animals[i] = new Dog();
for (int i = numberOfAnimals / 2; i < numberOfAnimals; ++ i)
    animals[i] = new Cat();
for (int i = 0; i < numberOfAnimals; i ++)
    delete animals[i];
std::cout <<"TEST DEEP COPY!!!"<<std::endl;
Dog dog1;
Dog dog2 = dog1;
Dog dog3;
dog3 = dog1;
Cat cat1;
Cat cat2 = cat1;
Cat cat3;
cat3 = cat1;
return 0;
}

/*int main()
{
const AAnimal* meta = new AAnimal();
const AAnimal* j = new Dog();
const AAnimal* i = new Cat();
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
}*/
