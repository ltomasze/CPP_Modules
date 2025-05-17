/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:09:50 by ltomasze          #+#    #+#             */
/*   Updated: 2025/05/04 13:14:59 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip> //for std::setw
#include "Contact.hpp"

class PhoneBook
{
	public:
		//PhoneBook() {}
		//~PhoneBook() {}
	    void addContact();
	    void searchContact();
	private:
		Contact contacts[8];
};

#endif