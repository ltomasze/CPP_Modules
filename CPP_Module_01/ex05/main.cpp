/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:07:20 by ltomasze          #+#    #+#             */
/*   Updated: 2025/05/27 13:58:08 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;

	std::cout << "[DEBUG]"  << std::endl;
	harl.complain("DEBUG");

	std::cout << "[INFO]" << std::endl;
    harl.complain("INFO");

    std::cout << "[WARNING]" << std::endl;
    harl.complain("WARNING");

    std::cout << "[ERROR]" << std::endl;
    harl.complain("ERROR");

	/*std::cout << "[42]" << std::endl;
    harl.complain("42");*/

    return 0;
}