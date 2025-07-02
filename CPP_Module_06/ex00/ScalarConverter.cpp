/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:38:15 by ltomasze          #+#    #+#             */
/*   Updated: 2025/07/02 16:08:10 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void) other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter() {};

void ScalarConverter :: convert( std::string literal )
{
    std::cout << std::fixed << std::setprecision(1);
	if (literal == "\\n")
	{
        literal = "\n";
    } 
	else if (literal == "\\t") 
	{
        literal = "\t";
    }
	else if (literal == "\\r") 
	{
	    literal = "\r";
	} 
	else if (literal == "\\v") 
	{
	    literal = "\v";
	} 
	else if (literal == "\\f") 
	{
	    literal = "\f";
	}
	if (literal.length() == 1) 
	{
    	char charValue = literal[0];
    	if (std::isprint(charValue)) 
		{
    	    std::cout << "char: '" << charValue << "'" << std::endl;
    	} 
		else 
		{
    	    std::cout << "char: Non displayable" << std::endl;
    	}
    	std::cout << "int: " << static_cast<int>(charValue) << std::endl;
    	std::cout << "float: " << static_cast<float>(charValue) << "f" << std::endl;
    	std::cout << "double: " << static_cast<double>(charValue) << std::endl;
    	return;
	}
    if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" || 
        literal == "+inff" || literal == "-inff") 
		{
        	std::cout << "char: impossible" << std::endl;
        	std::cout << "int: impossible" << std::endl;
			if (literal == "+inf" || literal == "-inf")
			{
        		std::cout << "float: " << literal << "f" << std::endl;
			}
			else
			{
        		std::cout << "float: " << literal << (literal[literal.size() - 1] == 'f' ? "" : "f") << std::endl;
			}
			if (literal == "nanf") 
			{
        		std::cout << "double: nan" << std::endl;
    		}
			else if (literal == "+inff")
			{
        		std::cout << "double: +inf" << std::endl;
			}
    		else if (literal == "-inff")
			{
        		std::cout << "double: -inf" << std::endl;
			}
    		else
			{
        		std::cout << "double: " << literal << std::endl;
			}
	       	/*std::cout << "float: " << literal << (literal[literal.size() - 1] == 'f' ? "" : "f") << std::endl;
        	std::cout << "double: " << literal << std::endl;*/
        	return;
    	}
    char* endPtr = NULL;
    long intValue = std::strtol(literal.c_str(), &endPtr, 10);
    if (*endPtr == '\0')
	{
        if (intValue >= std::numeric_limits<char>::min() && intValue <= std::numeric_limits<char>::max())
		{
            char charValue = static_cast<char>(intValue);
            if (std::isprint(charValue))
                std::cout << "char: '" << charValue << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        } 
		else 
		{
            std::cout << "char: impossible" << std::endl;
        }
        std::cout << "int: " << intValue << std::endl;
        std::cout << "float: " << static_cast<float>(intValue) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(intValue) << std::endl;
        return;
    }
    double doubleValue = std::strtod(literal.c_str(), &endPtr);
    if (*endPtr == '\0' || (*endPtr == 'f' && *(endPtr + 1) == '\0'))
	{
        if (doubleValue >= std::numeric_limits<char>::min() && doubleValue <= std::numeric_limits<char>::max()) 
		{
            char charValue = static_cast<char>(doubleValue);
            if (std::isprint(charValue))
                std::cout << "char: '" << charValue << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        } 
		else 
		{
            std::cout << "char: impossible" << std::endl;
        }
        if (doubleValue >= std::numeric_limits<int>::min() && doubleValue <= std::numeric_limits<int>::max()) 
		{
            std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
        } 
		else 
		{
            std::cout << "int: impossible" << std::endl;
        }
        std::cout << "float: " << static_cast<float>(doubleValue) << "f" << std::endl;
        std::cout << "double: " << doubleValue << std::endl;
        return;
    }
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}