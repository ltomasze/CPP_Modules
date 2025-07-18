/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:15:03 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/08 15:14:30 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main() 
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point point(1, 5);

    Fixed totalArea = calculateArea(a, b, c);
    Fixed area1 = calculateArea(point, b, c);
    Fixed area2 = calculateArea(a, point, c);
    Fixed area3 = calculateArea(a, b, point);

    if ((point.getX() == a.getX() && point.getY() == a.getY()) ||
        (point.getX() == b.getX() && point.getY() == b.getY()) ||
        (point.getX() == c.getX() && point.getY() == c.getY()))
    {
        std::cout << "Point is at a vertex of the triangle." << std::endl;
    }
    else if (totalArea == (area1 + area2 + area3) &&
             (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0)))
    {
        std::cout << "Point is on the edge of the triangle." << std::endl;
    }
    else if (totalArea == (area1 + area2 + area3))
    {
        std::cout << "Point is inside the triangle." << std::endl;
    }
    else
    {
        std::cout << "Point is outside the triangle." << std::endl;
    }

    return 0;
}