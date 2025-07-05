/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:34:48 by ltomasze          #+#    #+#             */
/*   Updated: 2025/07/05 15:20:55 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Unknown.hpp"
#include <iostream>

int main() {
    Base* randomObj = Base::generate();
    std::cout << "Identify by pointer: ";
    Base::identify(randomObj);
    std::cout << "Identify by reference: ";
    Base::identify(*randomObj);
    delete randomObj;

	Base* unknownObj = new Unknown();
    std::cout << "Identify by pointer: ";
    Base::identify(unknownObj);
    std::cout << "Identify by reference: ";
    Base::identify(*unknownObj);
    delete unknownObj;

	Base* emptyObj = NULL;
    std::cout << "Identify by pointer: ";
    Base::identify(emptyObj);
	if (emptyObj)
	{
		std::cout << "Identify by reference: ";
    	Base::identify(*emptyObj);
	}
	else
	{
		std::cout << "Identify by reference: Cannot dereference NULL" << std::endl;
	}
    return 0;
}