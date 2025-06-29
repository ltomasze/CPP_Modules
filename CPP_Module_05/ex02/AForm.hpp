/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:03:44 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/29 11:18:11 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

		AForm();

	public:
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm();

		const std::string& getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const & executer) const = 0;

		class GradeTooHighException : public std::exception
		{
    		public:
        		virtual const char* what() const throw();
    	};

		class GradeTooLowException : public std::exception
		{
    		public:
        		virtual const char* what() const throw();
    	};

		class FormNotSignedException : public std::exception
		{
		    public:
		        virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& outputStream, const AForm& form);

#endif