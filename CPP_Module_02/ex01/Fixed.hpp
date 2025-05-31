/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:15:48 by ltomasze          #+#    #+#             */
/*   Updated: 2025/05/31 17:20:15 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;
		
	public:
		Fixed();
		Fixed(const Fixed &sourceObj);
		Fixed(int value);
		Fixed(float value);
		~Fixed();

		Fixed &operator=(const Fixed &sourceObj);

		int getRawBits(void) const;
		void setRawBits(const int raw);
		float toFloat(void) const;
		int toInt(void) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif

