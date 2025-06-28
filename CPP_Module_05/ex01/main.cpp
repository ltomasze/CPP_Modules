/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:45:43 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/28 16:20:13 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Alicja", 42);
		Form f1("Form1", 50, 100);
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;

		b1.signForm(f1);

		Bureaucrat b2("Bartek", 150);
		Form f2("Form2", 75, 125);
		std::cout << f2 << std::endl;
		b2.signForm(f2);
		std::cout << f2 << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;	
}