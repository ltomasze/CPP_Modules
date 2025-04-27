/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:09:20 by ltomasze          #+#    #+#             */
/*   Updated: 2025/04/27 13:56:34 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <sstream>
#include <iostream>
#include <iomanip>

// Konstruktor
PhoneBook::PhoneBook() : contactCount(0), nextIndex(0) {
}

// Destruktor
PhoneBook::~PhoneBook() {
}

void PhoneBook::addContact()
{
	Contact newContact;
	std::string input;

	do {
        std::cout << "Enter first name: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "First name cannot be empty. Please try again." << std::endl;
    } while (input.empty());
    newContact.setFirstName(input);

	do {
        std::cout << "Enter last name: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Last name cannot be empty. Please try again." << std::endl;
    } while (input.empty());
    newContact.setLastName(input);

	do {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Nickname cannot be empty. Please try again." << std::endl;
    } while (input.empty());
    newContact.setNickname(input);

	do {
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Phone number cannot be empty. Please try again." << std::endl;
	} while (input.empty());
	newContact.setPhoneNumber(input);

	do {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << "Darkest secret cannot be empty. Please try again." << std::endl;
    } while (input.empty());
    newContact.setDarkestSecret(input);
	
	contacts[nextIndex] = newContact;
	
	nextIndex = (nextIndex + 1) % 8;
	if (contactCount < 8)
	{
		contactCount++;
	}

	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContact()
{
	if (contactCount == 0)
	{
		std::cout << "PhoneBook is empty. Add some contacts first!" << std::endl;
		return;
	}

	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	for (int i = 0; i < contactCount; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|"
				  << std::setw(10) << (contacts[i].getFirstName().length() > 10 ? contacts[i].getFirstName().substr(0, 9) + "." : contacts[i].getFirstName()) << "|"
				  << std::setw(10) << (contacts[i].getLastName().length() > 10 ? contacts[i].getLastName().substr(0, 9) + "." : contacts[i].getLastName()) << "|"
				  << std::setw(10) << (contacts[i].getNickname().length() > 10 ? contacts[i].getNickname().substr(0, 9) + "." : contacts[i].getNickname()) << std::endl;
	}
	std::cout << "Enter the index of the contact to display: ";
	std::string input;
	std::getline(std::cin, input);
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]))
		{
			std::cout << "Invalid input. Please enter a valid number." << std::endl;
			return;
		}
	}
	std::istringstream iss(input);
	int index;
	if (!(iss >> index))
	{
    	std::cout << "Invalid input. Please enter a valid number." << std::endl;
    	return;
	}
	if (index < 1 || index > contactCount)
    {
        std::cout << "Invalid index. Please enter a number between 1 and " << contactCount << "." << std::endl;
        return;
    }
	displayContact(index - 1);
	
}

void PhoneBook::displayContact(int index)
{
    const Contact& contact = contacts[index];

    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}