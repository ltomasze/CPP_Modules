/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:12:46 by ltomasze          #+#    #+#             */
/*   Updated: 2025/09/14 17:22:47 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>

std::string trim(const std::string& str) 
{
    size_t start = str.find_first_not_of(" \t\n\r"); // /r same like /n but when create file in windows
    size_t end = str.find_last_not_of(" \t\n\r");
    if (start == std::string::npos)
        return "";
    else
        return str.substr(start, end - start + 1);
}

bool isValidDate(const std::string& date) 
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') 
        return false;
    int year = std::atoi(date.substr(0, 4).c_str()); //c_str because I need const char*, not std::string
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (year < 2009 || year > 2025) 
        return false;
    if (month < 1 || month > 12) 
        return false;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;
    if (day < 1 || day > daysInMonth[month - 1]) 
        return false;
    return true;
}

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
	    // Tymczasowo wypisz linie
	    std::cout << date << "|"<< value << std::endl;
	}
    return 0;
}

