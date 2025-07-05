/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:43:06 by ltomasze          #+#    #+#             */
/*   Updated: 2025/07/05 15:00:12 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> //for rand() and srand();
#include <ctime>
#include <iostream>

Base* Base::generate()
{
	srand(time(0));
	int randomObj = rand() % 3;
	if (randomObj == 0)
		return new A();
	else if (randomObj == 1)
        return new B();
    else
        return new C();
}

void Base::identify(Base* p) 
{
	if(!p)
	{
		std::cout << "NULL" << std::endl;
        return;
	}
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void Base::identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
		//A& a = dynamic_cast<A&>(p);
		//(void)a;
        std::cout << "A" << std::endl;
        return;
    } 
	catch (std::exception& e) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } 
	catch (std::exception& e) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } 
	catch (std::exception& e) {}
    std::cout << "Unknown type" << std::endl;
}

/*Derived* d = dynamic_cast<Derived*>(basePtr);
if (d) 
{} 
else {}

try 
{
    Derived& d = dynamic_cast<Derived&>(baseRef);
}
	catch (std::bad_cast& e)
{
    std::cout << "Bad cast: " << e.what() << std::endl;
}
*/

//about catch I can make use:
//catch (std::exception& e)
//{
//    std::cout << "Exception: " << e.what() << std::endl;
//}
// or (...) <- all, but no details