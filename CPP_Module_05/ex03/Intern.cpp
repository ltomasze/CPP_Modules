/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:29:04 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/29 17:17:20 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) 
{ 
	(void)other; 
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* forms[3] = 
	{
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };
    for (int i = 0; i < 3; i++)
    {
        if (formName == formTypes[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            for (int j = 0; j < 3; j++)
                if (j != i)
                    delete forms[j];
            return forms[i];
        }
    }
    std::cerr << "Error: Form name \"" << formName << "\" does not exist." << std::endl;
    for (int j = 0; j < 3; j++)
        delete forms[j];
    return NULL;
}