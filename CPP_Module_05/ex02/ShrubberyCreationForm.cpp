/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 12:15:46 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/29 15:25:26 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	:AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
        throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
	std::ofstream file((target + "_shrubbery").c_str()); 
	//.c_ str <- std::string to const char*, this is for ofstream
    if (!file.is_open())
        throw std::ios_base::failure("Failed to open file");
    file << "   ^   \n"
     	 << "  /|\\  \n"
     	 << " /_|_\\ \n"
     	 << "   |   \n";
    file.close();
    std::cout << "Shrubbery has been created in " << target << "_shrubbery" << std::endl;
}



