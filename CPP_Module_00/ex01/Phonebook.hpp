/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:00:45 by ltomasze          #+#    #+#             */
/*   Updated: 2025/04/26 17:06:48 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
private:
	Contact contacts[8];
	int contactCount;
	int nextIndex;
public:
	PhoneBook();
	~PhoneBook();
	
	void addContact();
	void searchContact();
	void displayContact(int index);
};

#endif