/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:45:43 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/29 15:33:49 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	std::cout << "TEST1" << std::endl;
	try
	{
		Bureaucrat b1("Alicja", 42);
		ShrubberyCreationForm shrubberyForm("parkA");
		std::cout << shrubberyForm << std::endl;
		b1.signForm(shrubberyForm);
		std::cout << shrubberyForm << std::endl;
		shrubberyForm.execute(b1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "TEST2" << std::endl;
    try
    {
        Bureaucrat b2("Bartek", 42);
        RobotomyRequestForm robotomyForm("Target1");
        std::cout << robotomyForm << std::endl;
        b2.signForm(robotomyForm);
        std::cout << robotomyForm << std::endl;
        robotomyForm.execute(b2);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

	return 0;	
}