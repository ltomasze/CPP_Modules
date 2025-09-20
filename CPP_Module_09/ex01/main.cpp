/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:32:07 by ltomasze          #+#    #+#             */
/*   Updated: 2025/09/20 17:59:20 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
	{
        std::cerr << "Error" << std::endl;
        return 1;
    }
    RPN rpn;
    int result = rpn.processExpression(argv[1]);
    if (result == -1) 
    {
        return 1;
    }
    std::cout << result << std::endl;
    return 0;
}