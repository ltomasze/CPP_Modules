/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:23:17 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/28 16:19:52 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
	{
		if (gradeToSign < 1 ||gradeToExecute < 1)
			throw GradeTooHighException();
		if (gradeToSign > 150 || gradeToExecute > 150)
			throw GradeTooLowException();
	}

Form::Form(const Form& other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form& Form::operator=(const Form& other)
{
	if(this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form() {}

const std::string& Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getGradeToSign() const 
{
    return gradeToSign;
}

int Form::getGradeToExecute() const 
{
    return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& Bureaucrat)
{
	if(Bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;	
}

const char* Form::GradeTooHighException::what() const throw() 
{
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() 
{
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& outputStream, const Form& form) 
{
    outputStream << form.getName()
                 << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
                 << ", Grade to Sign: " << form.getGradeToSign()
                 << ", Grade to Execute: " << form.getGradeToExecute();
    return outputStream;
}

