/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:26:20 by ltomasze          #+#    #+#             */
/*   Updated: 2025/05/11 13:22:10 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 5;
	Zombie* zhorde = zombieHorde(N, "Zombie");
	if(zhorde)
	{
		/*for (int i = 0; i < N; i++)
		{
			std::ostringstream oss;
			oss << "Zombie" << (i+1);
			zhorde[i].setName(oss.str());
		}*/
		for(int i = 0; i < N; i++)
		{
			zhorde[i].announce();
		}
		delete[] zhorde;
	}
	else
	{
		std::cerr << "Failed to create zombie horde." << std::endl;
	}
	return 0;
}