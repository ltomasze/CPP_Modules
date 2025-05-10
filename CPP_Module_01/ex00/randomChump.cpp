/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:23:22 by ltomasze          #+#    #+#             */
/*   Updated: 2025/05/10 17:44:26 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie stackZombie = Zombie(name); //create zombie on stack(stos)
	//Zombie stackZombie(name);
	stackZombie.announce();	// announce the zombie
}