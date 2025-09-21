/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:41:04 by ltomasze          #+#    #+#             */
/*   Updated: 2025/09/21 15:28:16 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <cstddef>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void sortVector(std::vector<int>& vec); //we need this method to prottect recursion 
    void sortDeque(std::deque<int>& deq);

private:
    void fordJohnsonSortVector(std::vector<int>& vec);
    void fordJohnsonSortDeque(std::deque<int>& deq);

    std::vector<size_t> jacobsthalIndices(size_t n) const;

    void binaryInsertVector(std::vector<int>& vec, int value, size_t end);
    void binaryInsertDeque(std::deque<int>& deq, int value, size_t end);
};
