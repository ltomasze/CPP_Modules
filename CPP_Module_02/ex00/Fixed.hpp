/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:15:48 by ltomasze          #+#    #+#             */
/*   Updated: 2025/05/29 16:50:55 by ltomasze         ###   ########.fr       */
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
		Fixed(const Fixed &other);
		~Fixed();
		Fixed &operator=(const Fixed &other);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif

/*static oznacza że pole bitów ułamkowych należy do całej klasy a nie do konkretnego obiektu*/

/*konstruktor kopiujący
	ClassName(const ClassName &other)
	{
		this->field1 = other._field1;
		this->field2 = other._field2;
	}*/

/*operator przypisania
	ClassName &ClassName::operator=(const ClassName &other)
	{
		if (this !=other) sprawdzenie czy nie przepisujemy obiektu do samego siebie;
		{
			this->field1 = other._field1; kopiowanie wartości z obiektu other
			this->field2 = other._field2;
		}
		return *this; zwracanie referencji do bieżącego obiektu(umożliwia to łańcuchowe
						przypisanie np. a=b=c;)
	}
}*/

