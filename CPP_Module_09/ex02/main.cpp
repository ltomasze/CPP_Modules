/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:40:30 by ltomasze          #+#    #+#             */
/*   Updated: 2025/09/21 16:34:31 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    // Zakładamy, że wejście jest poprawne (same dodatnie liczby całkowite)
    std::vector<int> numbers;
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        int num;
        iss >> num;
        numbers.push_back(num);
    }

    // Przed sortowaniem
    std::cout << "Before:";
    for (size_t i = 0; i < numbers.size(); ++i)
        std::cout << " " << numbers[i];
    std::cout << std::endl;

	PmergeMe pm;

    // Pomiar czasu dla vector (tworzenie + sortowanie)
    clock_t startVec = clock();
    std::vector<int> vec(numbers);
    pm.sortVector(vec);
    clock_t endVec = clock();

    // Pomiar czasu dla deque (tworzenie + sortowanie)
    clock_t startDeq = clock();
    std::deque<int> deq(numbers.begin(), numbers.end());
    pm.sortDeque(deq);
    clock_t endDeq = clock();

    // Po sortowaniu
    std::cout << "After:";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << " " << vec[i];
    std::cout << std::endl;

    // Wyniki czasowe
    double timeVec = 1000000.0 * (endVec - startVec) / CLOCKS_PER_SEC;
    double timeDeq = 1000000.0 * (endDeq - startDeq) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << numbers.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << numbers.size()
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;

    return 0;
}