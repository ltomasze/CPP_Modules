/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:25:35 by ltomasze          #+#    #+#             */
/*   Updated: 2025/04/27 16:02:14 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		for (int i = 1; i < ac; i++)
		{
			for (int j = 0; av[i][j]; j++)
			{
				std::cout << (char)toupper(av[i][j]);
			}
			if (i < ac - 1)
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}

/*int main (int ac, char **av)
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
}*/