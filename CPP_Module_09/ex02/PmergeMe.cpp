/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:40:47 by ltomasze          #+#    #+#             */
/*   Updated: 2025/09/21 10:41:06 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : timeA(0), timeB(0) {}

PmergeMe::PmergeMe(const PmergeMe& other)
    : containerA(other.containerA), containerB(other.containerB),
      timeA(other.timeA), timeB(other.timeB) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) 
{
    if (this != &other) 
	{
        containerA = other.containerA;
        containerB = other.containerB;
        timeA = other.timeA;
        timeB = other.timeB;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::processInput(const std::vector<int>& input) 
{
    // Podział na pary
    for (size_t i = 0; i < input.size(); i += 2) 
	{
        if (i + 1 < input.size()) 
		{
            if (input[i] > input[i + 1]) 
			{
                containerA.push_back(input[i]);
                containerB.push_back(input[i + 1]);
            } 
			else 
			{
                containerA.push_back(input[i + 1]);
                containerB.push_back(input[i]);
            }
        } 
		else 
            containerA.push_back(input[i]); // Ostatni element (nieparzysty)
    }
    // Sortowanie kontenera A
    clock_t startA = clock();
    std::sort(containerA.begin(), containerA.end());
    clock_t endA = clock();
    timeA = static_cast<double>(endA - startA) / CLOCKS_PER_SEC * 1e6; // Czas w mikrosekundach
    // Wstawianie liczb z kontenera B
    clock_t startB = clock();
    for (size_t j = 0; j < containerB.size(); ++j) 
	{
        std::vector<int>::iterator pos = std::lower_bound(containerA.begin(), containerA.end(), containerB[j]);
        containerA.insert(pos, containerB[j]);
    }
    clock_t endB = clock();
    timeB = static_cast<double>(endB - startB) / CLOCKS_PER_SEC * 1e6; // Czas w mikrosekundach
}

void PmergeMe::displayResults() const 
{
    // Wyświetlanie posortowanej sekwencji
    std::cout << "After: ";
    for (size_t i = 0; i < containerA.size(); ++i) 
	{
        std::cout << containerA[i] << " ";
    }
    std::cout << "\n";
    // Wyświetlanie czasu wykonania
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << containerA.size() << " elements with std::vector: " << timeA << " us\n";
    std::cout << "Time to process a range of " << containerA.size() << " elements with std::deque: " << timeB << " us\n";
}