/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:16:01 by ltomasze          #+#    #+#             */
/*   Updated: 2025/05/31 18:44:02 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &sourceObj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = sourceObj;
}

Fixed::Fixed(int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << _fractionalBits;
	//10 << 8 = 10 * 256 = 2560
}

Fixed::Fixed(float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
	/* 1 << 256 next 42.42 * 256 = 10859.52 czyli najbliżej do 10860*/
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &sourceObj)
{
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &sourceObj)
	{
		this->setRawBits(sourceObj.getRawBits());
		//this->_fixedPointValue = sourceObj._fixedPointValue;
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	//std::cout <<"getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
	/*ponieważ _fixedPointValue jest stałoprzecinkowa to należy dokonać 
	rzutowania bo float jest zmiennoprzecinkową*/
}

int Fixed::toInt(void) const
{
	return this->_fixedPointValue >> _fractionalBits;
	/* lub liczba dzielona przez 256 bo 8 bitów
	stałoprzecinkowa na całkowitą*/
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
/*przeciązenie operatora << służy do wypyisywania różnego rodzaju typu danych
na wskazany typ, jest poza klasą bo jest globalny bo ma std::ostream

ostream to strumień wyjściowy

std::ostream &operator<<(std::ostream &out, const YourClass &obj)
{
    Wypisz dane obiektu obj do strumienia out
    out << obj.someData; Możesz użyć metod lub pól obiektu obj
    Zwróć referencję do strumienia wyjściowego
    return out;
}*/