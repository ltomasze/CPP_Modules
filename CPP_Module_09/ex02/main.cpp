/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:40:30 by ltomasze          #+#    #+#             */
/*   Updated: 2025/09/21 10:24:27 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char* argv[]) 
{
    if (argc < 2) 
	{
        std::cerr << "Error\n";
        return 1;
    }
    std::vector<int> input;
    for (int i = 1; i < argc; ++i) 
	{
        std::istringstream iss(argv[i]);
        int num;
        if (!(iss >> num) || num <= 0) { // check argv, iis >> num <- this is convert str for int
            std::cerr << "Error\n";
            return 1;
        }
        input.push_back(num); //add num for end od containers
    }
    std::cout << "Before: ";
    for (size_t i = 0; i < input.size(); ++i) 
	{
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
    // Utworzenie obiektu klasy PmergeMe i przetworzenie danych
    PmergeMe sorter;
    sorter.processInput(input);
    sorter.displayResults();
    return 0;
}