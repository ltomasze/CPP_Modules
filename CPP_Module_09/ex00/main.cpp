/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:12:46 by ltomasze          #+#    #+#             */
/*   Updated: 2025/09/14 16:42:35 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

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
	    std::string date = line.substr(0, pipePos);
	    std::string value = line.substr(pipePos + 1);
	    // Tymczasowo wypisz linie
	    std::cout << date << "|"<< value << std::endl;
	}
    return 0;
}

