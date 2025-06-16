/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:59:01 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/15 18:00:56 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain has been created!" << std::endl;
}

Brain::Brain(const Brain& sourceObj)
{
    for (int i = 0; i < 100; ++i)
        ideas[i] = sourceObj.ideas[i];
    std::cout << "Brain has been copied!" << std::endl;
}

Brain& Brain::operator=(const Brain& sourceObj)
{
    if (this != &sourceObj)
    {
        for (int i = 0; i < 100; ++i) //deep copy
            ideas[i] = sourceObj.ideas[i];
    }
    std::cout << "Brain has been assigned!" << std::endl;
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain has been destroyed!" << std::endl;
}