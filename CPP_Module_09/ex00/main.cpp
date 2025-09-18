/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:12:46 by ltomasze          #+#    #+#             */
/*   Updated: 2025/09/18 12:38:39 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) 
{
    if (argc != 2)
	{
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    std::ifstream file(argv[1]);
    if (!file.is_open()) 
	{
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
	std::string line;
	bool isFirstLine = true;
	while (std::getline(file, line))
	{
		if (isFirstLine) 
		{
		    isFirstLine = false;
		    if (!std::isdigit(line[0])) 
		        continue;
		}
	    if (line.empty())
	        continue;
	    std::string::size_type pipePos = line.find('|'); //size_type is the most size for the string, the last index is npos!
	    if (pipePos == std::string::npos)//npos is the special value for find, when dont find:)
		{
	        std::cerr << "Error: bad input => " << line << std::endl;
	        continue;
	    }
	    std::string date = trim(line.substr(0, pipePos));
	    std::string value = trim(line.substr(pipePos + 1));
		if (!isValidDate(date)) 
		{
		    std::cerr << "Error: bad input => " << line << std::endl;
		    continue;
		}
		std::string errorMessage;
		if (!isValidValue(value, errorMessage)) 
    	{
    	    std::cerr << errorMessage << std::endl;
    	    continue;
    	}
	    //Tymczasowo wypisz linie
	    std::cout << date << "|"<< value << std::endl;
	}
    return 0;
}

