/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:55:40 by ltomasze          #+#    #+#             */
/*   Updated: 2025/07/08 17:01:38 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() 
{
    try 
	{
        std::vector<int> vec;
		vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        std::cout << "Test vector:" << std::endl;
        std::cout << "Found: " << *easyfind(vec, 4) << std::endl;
        std::cout << "Found: " << *easyfind(vec, 6) << std::endl;
    }
	catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try 
	{
        std::list<int> lst;
		lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);
        std::cout << "Test list:" << std::endl;
        std::cout << "Found: " << *easyfind(lst, 40) << std::endl;
        std::cout << "Found: " << *easyfind(lst, 60) << std::endl;
    } 
	catch (const std::exception& e) 
	{
        std::cerr << e.what() << std::endl;
    }
    return 0;
}