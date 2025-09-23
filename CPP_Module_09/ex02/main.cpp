/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:40:30 by ltomasze          #+#    #+#             */
/*   Updated: 2025/09/23 14:46:55 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
	if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::vector<int> numbers;
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        int num;
		char extra; //for example "1.1"
		if (!(iss >> num) || num <= 0 || (iss >> extra))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
	if (std::find(numbers.begin(), numbers.end(), num) != numbers.end())
    {
        continue;
    }
    
        numbers.push_back(num);
    }
    std::cout << "Before:";
    for (size_t i = 0; i < numbers.size(); ++i)
        std::cout << " " << numbers[i];
    std::cout << std::endl;

	PmergeMe pm;

    clock_t startVec = clock();
    std::vector<int> vec(numbers);
    pm.sortVector(vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    std::deque<int> deq(numbers.begin(), numbers.end());
    pm.sortDeque(deq);
    clock_t endDeq = clock();

    std::cout << "After:";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << " " << vec[i];
    std::cout << std::endl;

    double timeVec = 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC;
    double timeDeq = 1000000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << numbers.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << numbers.size()
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;

    return 0;
}