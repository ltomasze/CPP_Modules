/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:25:35 by ltomasze          #+#    #+#             */
/*   Updated: 2025/04/24 14:05:40 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int ac, char **av)
{
	int i = 1;
	int j = 0;
	char c;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; 
	}
	else
	{
		while(av[i])
		{
			j = 0;
			while(av[i][j])
			{
				c = av[i][j];
				if (c >= 'a' && c <= 'z')
					c = c - 32;
				std::cout << c;
				j++;
			}
			if(av[i + 1])
				std::cout << " ";
			i++;
		}
	}
	std::cout << "\n";
	return (0);
}