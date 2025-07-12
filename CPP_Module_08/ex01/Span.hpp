/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:25:56 by ltomasze          #+#    #+#             */
/*   Updated: 2025/07/12 17:17:07 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector> // for container, size
#include <exception>
#include <algorithm> //for sort, min_element, max_element
#include <iostream>
#include <climits>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
		Span();
	public:
		Span(unsigned int_maxSize);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan() const;
		int longestSpan() const;
		
		class SpanFullException: public std::exception
		{
			const char* what() const throw(); 
			//no need add virtual for begin becausse "what" in basic is always virtual
		};
		class NotEnoughNumbersException : public std::exception 
		{
        	const char* what() const throw();
    	};

};
