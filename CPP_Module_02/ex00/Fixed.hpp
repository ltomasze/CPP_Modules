/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:15:48 by ltomasze          #+#    #+#             */
/*   Updated: 2025/05/31 16:22:31 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;
		
	public:
		Fixed();
		Fixed(const Fixed &sourceObj);
		~Fixed();
		Fixed &operator=(const Fixed &sourceObj);

		int getRawBits(void) const;
		void setRawBits(const int raw);
};

#endif

// :: operator zakresu

/*static oznacza że pole bitów ułamkowych należy do całej klasy a nie do konkretnego obiektu*/

/*konstruktor kopiujący
	ClassName(const ClassName &sourceObj)
	{
		this->field1 = other._field1;
		this->field2 = other._field2;
	}*/

/*operator przypisania
	ClassName &ClassName::operator=(const ClassName &sourceObj)
	{
		if (this !=sourceObj) sprawdzenie czy nie przepisujemy obiektu do samego siebie;
		{
			this->field1 = sourceObj._field1; kopiowanie wartości z obiektu sourceObj
			this->field2 = sourceObj._field2;
		}
		return *this; zwracanie referencji do bieżącego obiektu(umożliwia to łańcuchowe
						przypisanie np. a=b=c;)
	}
}*/

/*int getRawBits(void) const; oznacza że metoda jest stała i zmienia stanu obiektu*/
