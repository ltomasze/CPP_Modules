/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:03:47 by ltomasze          #+#    #+#             */
/*   Updated: 2025/04/27 13:07:51 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <string>

int main()
{
    PhoneBook phoneBook; // Tworzymy instancję książki telefonicznej
    std::string command;

    std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;

    while (true)
    {
        // Wyświetl menu
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        // Obsługa komend
        if (command == "ADD")
        {
            phoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContact();
        }
        else if (command == "EXIT")
        {
            std::cout << "Exiting PhoneBook. Goodbye!" << std::endl;
            break; // Zakończ pętlę i program
        }
        else
        {
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
        }

        // Sprawdź, czy strumień wejściowy jest w dobrym stanie
        if (std::cin.eof())
        {
            std::cout << "EOF detected. Exiting PhoneBook." << std::endl;
            break;
        }
    }

    return 0;
}