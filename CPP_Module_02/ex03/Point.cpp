/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:32:31 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/08 14:36:04 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float xValue, const float yValue) : x(xValue), y(yValue) {}

Point::Point(const Point &source) : x(source.x), y(source.y) {}

Point &Point::operator=(const Point &source)
{
    if (this != &source) 
	{}
    return *this;
}
//nic nie można przypisać bo x i y jest stałe

Point::~Point() {}

Fixed Point::getX() const 
{
    return this->x;
}

Fixed Point::getY() const
{
    return this->y;
}