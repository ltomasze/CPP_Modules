/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:24:13 by ltomasze          #+#    #+#             */
/*   Updated: 2025/05/11 12:51:33 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cerr << "Error: N must be greater than 0." << std::endl;
		return (NULL);
	}
	Zombie* zHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zHorde[i].setName(name);
	}
	return (zHorde);
}
