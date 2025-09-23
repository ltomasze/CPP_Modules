/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:40:47 by ltomasze          #+#    #+#             */
/*   Updated: 2025/09/23 12:11:07 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }
PmergeMe::~PmergeMe() {}

void PmergeMe::sortVector(std::vector<int>& vec)
{
    if (vec.size() < 2)
        return;
    fordJohnsonSortVector(vec);
}

void PmergeMe::sortDeque(std::deque<int>& deq)
{
    if (deq.size() < 2)
        return;
    fordJohnsonSortDeque(deq);
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& vec) 
{
    size_t n = vec.size();
    if (n < 2)
        return;
    std::vector<int> mainChain;
    std::vector<int> pending;
    size_t i = 0;
    for (/*size_t i = 0*/; i + 1 < n; i += 2) 
	{
        if (vec[i] < vec[i + 1]) 
		{
            mainChain.push_back(vec[i + 1]);
            pending.push_back(vec[i]);
        } 
		else 
		{
            mainChain.push_back(vec[i]);
            pending.push_back(vec[i + 1]);
        }
    }
    if (i < n)
        mainChain.push_back(vec[i]); //check when the index is odd
    fordJohnsonSortVector(mainChain);
    if (!pending.empty())
        binaryInsertVector(mainChain, pending[0], 1);
    std::vector<size_t> indices = jacobsthalIndices(pending.size());
    for (size_t j = 1; j < pending.size(); ++j) 
	{
        size_t idx = indices[j - 1];
        if (idx < pending.size())
            binaryInsertVector(mainChain, pending[idx], idx + j + 1);
    }
    vec = mainChain;
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& deq)
{
    size_t n = deq.size();
    if (n < 2)
        return;
    std::deque<int> mainChain;
    std::deque<int> pending;
    size_t i = 0;
    for (; i + 1 < n; i += 2) 
	{
        if (deq[i] < deq[i + 1]) {
            mainChain.push_back(deq[i + 1]);
            pending.push_back(deq[i]);
        } 
		else 
		{
            mainChain.push_back(deq[i]);
            pending.push_back(deq[i + 1]);
        }
    }
    if (i < n)
        mainChain.push_back(deq[i]);
    fordJohnsonSortDeque(mainChain);
    if (!pending.empty())
        binaryInsertDeque(mainChain, pending[0], 1);
    std::vector<size_t> indices = jacobsthalIndices(pending.size());
    for (size_t j = 1; j < pending.size(); ++j) 
	{
        size_t idx = indices[j - 1];
        if (idx < pending.size())
            binaryInsertDeque(mainChain, pending[idx], idx + j + 1);
    }
    deq = mainChain;
}

std::vector<size_t> PmergeMe::jacobsthalIndices(size_t n) const 
{
    std::vector<size_t> jacob;
    if (n == 0)
        return jacob;
    jacob.push_back(0);
    if (n == 1)
        return jacob;
    jacob.push_back(1);
    size_t k = 2;
    while (true) 
	{
        size_t next = jacob[k - 1] + 2 * jacob[k - 2];
        if (next >= n)
            break;
        jacob.push_back(next);
        ++k;
    }
    std::vector<size_t> indices;
    for (size_t i = 1; i < jacob.size(); ++i)
        indices.push_back(jacob[i]);
    for (size_t i = 0; i < n; ++i) {
        if (std::find(indices.begin(), indices.end(), i) == indices.end())
            indices.push_back(i);
    }
    return indices;
}

void PmergeMe::binaryInsertVector(std::vector<int>& vec, int value, size_t end) 
{
    size_t left = 0;
    size_t right = end;
    while (left < right) 
	{
        size_t mid = left + (right - left) / 2;
        if (value < vec[mid])
            right = mid;
        else
            left = mid + 1;
    }
    vec.insert(vec.begin() + left, value);
}

void PmergeMe::binaryInsertDeque(std::deque<int>& deq, int value, size_t end) 
{
    size_t left = 0;
    size_t right = end;
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (value < deq[mid])
            right = mid;
        else
            left = mid + 1;
    }
    deq.insert(deq.begin() + left, value);
}