/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:23:17 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/28 16:19:52 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
	{
		if (gradeToSign < 1 ||gradeToExecute < 1)
			throw GradeTooHighException();
		if (gradeToSign > 150 || gradeToExecute > 150)
			throw GradeTooLowException();
	}

AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other)
{
	if(this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getGradeToSign() const 
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const 
{
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& Bureaucrat)
{
	if(Bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;	
}

const char* AForm::GradeTooHighException::what() const throw() 
{
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() 
{
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& outputStream, const AForm& form) 
{
    outputStream << form.getName()
                 << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
                 << ", Grade to Sign: " << form.getGradeToSign()
                 << ", Grade to Execute: " << form.getGradeToExecute();
    return outputStream;
}

