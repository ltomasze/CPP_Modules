/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:25:52 by ltomasze          #+#    #+#             */
/*   Updated: 2025/04/26 16:51:20 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}
Contact::~Contact()
{
}
void Contact::setFirstName(std::string word)
{
	firstName = word;
}
void Contact::setLastName(std::string word)
{
	lastName = word;
}
void Contact::setNickname(std::string word)
{
	nickname = word;
}
void Contact::setPhoneNumber(std::string word)
{
	phoneNumber = word;
}
void Contact::setDarkestSecret(std::string word)
{
	darkestSecret = word;
}
std::string Contact::getFirstName() const
{
	return firstName;
}

std::string Contact::getLastName() const
{
	return lastName;
}

std::string Contact::getNickname() const
{
	return nickname;
}

std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}
