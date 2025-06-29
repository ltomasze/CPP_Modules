/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:45:43 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/29 17:33:02 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "TEST1" << std::endl;
	try
	{
		Bureaucrat b1("Alicja", 42);
		ShrubberyCreationForm shrubberyForm("Target1");
		std::cout << shrubberyForm << std::endl;
		b1.signForm(shrubberyForm);
		std::cout << shrubberyForm << std::endl;
		b1.executeForm(shrubberyForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "TEST2" << std::endl;
    try
    {
        Bureaucrat b2("Bartek", 42);
        RobotomyRequestForm robotomyForm("Target2");
        std::cout << robotomyForm << std::endl;
        b2.signForm(robotomyForm);
        std::cout << robotomyForm << std::endl;
        b2.executeForm(robotomyForm);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
	std::cout << "TEST3" << std::endl;
	try
	{
	    Bureaucrat b3("Cezary", 5);
	    PresidentialPardonForm pardonForm("Target3");
	    std::cout << pardonForm << std::endl;
	    b3.signForm(pardonForm);
	    std::cout << pardonForm << std::endl;
	    b3.executeForm(pardonForm);
	}
	catch (const std::exception& e)
	{
	    std::cerr << e.what() << std::endl;
	}
	std::cout << "TEST4" << std::endl;
	Intern someRandomIntern;
	AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		try
        {
            Bureaucrat b4("Darek", 1);
            b4.signForm(*rrf);
            b4.executeForm(*rrf);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
		delete rrf;
	}
	else
    {
        std::cerr << "Failed to create form." << std::endl;
    }
	return 0;
}