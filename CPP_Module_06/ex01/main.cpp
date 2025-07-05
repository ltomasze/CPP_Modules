/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:16:09 by ltomasze          #+#    #+#             */
/*   Updated: 2025/07/05 13:16:59 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() 
{
    Data originalData;
	originalData.value = 42;
	originalData.name = "Example";
    //Data originalData = {42, "Example"};
    Data* originalPtr = &originalData;
    std::cout << "Original Data:" << "Value: " << originalPtr->value 
			<< ", Name:" << originalPtr->name;
    uintptr_t raw = Serializer::serialize(originalPtr);
    std::cout << ", Serialized value (uintptr_t): " << raw << std::endl;
    Data* deserializedPtr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data:" << "Value: " << deserializedPtr->value 
			<< ", Name: " << deserializedPtr->name << std::endl;
    std::cout << "Pointer comparison: ";
    if (originalPtr == deserializedPtr)
	{
        std::cout << "Pointers match!" << std::endl;
    } 
	else 
	{
        std::cout << "Pointers do not match!" << std::endl;
    }
	deserializedPtr->value = 77;
    deserializedPtr->name = "Change Example";
    std::cout << "Change Deserialized Data:" 
              << " Value: " << deserializedPtr->value 
              << ", Name: " << deserializedPtr->name << std::endl;

    return 0;
}