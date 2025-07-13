/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:59:48 by ltomasze          #+#    #+#             */
/*   Updated: 2025/07/13 11:55:05 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <iterator>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {} //create empty stack(PL-stos)
		MutantStack(const MutantStack& other) : std::stack<T>(other) {}
		MutantStack& operator=(const MutantStack& other)
		{
			if (this != &other)
			{
				std::stack<T>::operator=(other);
			}
			return *this;
		}
		~MutantStack() {}
		
		typedef typename std::stack<T>::container_type::iterator iterator;
    	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    	iterator begin() 
		{ 
			return std::stack<T>::c.begin(); 
		}

    	iterator end() 
		{ 
			return std::stack<T>::c.end(); 
		}

    	const_iterator begin() const 
		{ 
			return std::stack<T>::c.begin(); 
		}
    	
		const_iterator end() const 
		{ 
			return std::stack<T>::c.end(); 
		}
};