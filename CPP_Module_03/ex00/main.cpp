/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:10:58 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/15 13:11:02 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap noName;
    ClapTrap bot1("Bot1");
    ClapTrap bot2("Bot2");
    ClapTrap bot3(bot1);
    noName = bot1;

    for (int i = 0; i < 11; i++)
    {
        bot1.attack("Bot2");
        bot2.takeDamage(1);
        bot2.beRepaired(1);
    }
    return 0;
}
/*
int main()
{
    ClapTrap bot1("Bot1");
    ClapTrap bot2("Bot2");

    for (int i = 0; i < 3; i++)
    {
        bot1.attack("Bot2");
        bot2.takeDamage(5);
        bot2.beRepaired(1);
    }
    return 0;
}*/
