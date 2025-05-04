/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:04:15 by ltomasze          #+#    #+#             */
/*   Updated: 2025/05/04 14:29:11 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Welcome to My Awesome PhoneBook, use ADD, SEARCH or EXIT!" << std::endl;

    while (true)
    {
        std::cout << "Enter a command: ";
		if (!std::getline(std::cin, command))
    	{
    	    if (std::cin.eof())
    	        std::cout << "Ctrl+D pressed, exiting PhoneBook." << std::endl;
    	    else
    	        std::cerr << "Error reading input. Exiting." << std::endl;
    	    break;
    	}
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
        {
            std::cout << "Exiting PhoneBook. Goodbye!" << std::endl;
            break;
        }
        else
            std::cout << "Please enter ADD, SEARCH, or EXIT." << std::endl;
    }
    return 0;
}