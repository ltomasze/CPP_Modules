/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:16:09 by ltomasze          #+#    #+#             */
/*   Updated: 2025/07/02 18:17:19 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() 
{
    // Utworzenie obiektu Data
    Data originalData = {42, "Example"};
    Data* originalPtr = &originalData;

    // Wyświetlenie oryginalnych danych
    std::cout << "Original Data:" << std::endl;
    std::cout << "Value: " << originalPtr->value << ", Name: " << originalPtr->name << std::endl;

    // Serializacja wskaźnika
    uintptr_t raw = Serializer::serialize(originalPtr);
    std::cout << "\nSerialized value (uintptr_t): " << raw << std::endl;

    // Deserializacja wskaźnika
    Data* deserializedPtr = Serializer::deserialize(raw);
    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "Value: " << deserializedPtr->value << ", Name: " << deserializedPtr->name << std::endl;

    // Sprawdzenie wskaźników
    std::cout << "\nPointer comparison:" << std::endl;
    if (originalPtr == deserializedPtr) {
        std::cout << "Pointers match!" << std::endl;
    } else {
        std::cout << "Pointers do not match!" << std::endl;
    }

    return 0;
}