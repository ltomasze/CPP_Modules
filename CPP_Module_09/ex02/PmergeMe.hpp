/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:41:04 by ltomasze          #+#    #+#             */
/*   Updated: 2025/09/21 10:39:27 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <algorithm> // for sort
#include <iomanip> // for setprecision

class PmergeMe
{
	public:
		PmergeMe();
    	PmergeMe(const PmergeMe& other);
    	PmergeMe& operator=(const PmergeMe& other);
    	~PmergeMe(); 

		void processInput(const std::vector<int>& input);
		void displayResults() const;

	private:
    	std::vector<int> containerA;
    	std::deque<int> containerB;
    	double timeA;
    	double timeB;
};
