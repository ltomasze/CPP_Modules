/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:24:35 by ltomasze          #+#    #+#             */
/*   Updated: 2025/05/11 13:04:47 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		//Zombie(std::string name);
		~Zombie();
		void setName(std::string name);
		void announce() const;
};

Zombie* zombieHorde(int N, std::string name);

#endif