/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:24:49 by ltomasze          #+#    #+#             */
/*   Updated: 2025/07/12 17:40:23 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}

// int main()
// {
//     try 
// 	{
//         Span sp(10000);
//         for (int i = 0; i < 5000; ++i)
// 		{
//             sp.addNumber(i);
//         }
//         std::vector<int> sp1;
//         for (int i = 15000; i < 20000; ++i) 
// 		{
//             sp1.push_back(i);
//         }
//         sp.addNumbers(sp1.begin(), sp1.end());
//         std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
//         std::cout << "Longest span: " << sp.longestSpan() << std::endl;
//     } 
// 	catch (const std::exception& e) 
// 	{
//         std::cerr << e.what() << std::endl;
//     }
//     return 0;
// }