/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:45:43 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/29 13:23:18 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Alicja", 42);
		ShrubberyCreationForm shrubberyForm("forest");
		std::cout << shrubberyForm << std::endl;
		b1.signForm(shrubberyForm);
		std::cout << shrubberyForm << std::endl;
		shrubberyForm.execute(b1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;	
}