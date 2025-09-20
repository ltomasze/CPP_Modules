/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:31:45 by ltomasze          #+#    #+#             */
/*   Updated: 2025/09/20 18:13:44 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other)
{
    (void)other;
}

RPN& RPN::operator=(const RPN& other) 
{
    if (this != &other)
	{
    }
    return *this;
}

RPN::~RPN() {}

int RPN::processExpression(const std::string& expression) const
{
    std::stack<int> stack;
    for (size_t i = 0; i < expression.size(); ++i)
	{
        char token = expression[i];
        if (std::isspace(token)) 
		{
            continue;
        } 
		else if (std::isdigit(token)) 
		{
            stack.push(token - '0'); // convert digital for number
        } 
		else if (isOperator(token)) 
		{
            if (stack.size() < 2) 
			{
                std::cerr << "Error" << std::endl;
            	return -1;
            }
            int b = stack.top(); stack.pop(); //top-download value for top, pop-delete value for top
            int a = stack.top(); stack.pop();
            stack.push(executeOperation(token, a, b));
        } else
		{
            std::cerr << "Error" << std::endl;
            return -1;
        }
    }
    if (stack.size() != 1)
	{
        std::cerr << "Error" << std::endl;
        return -1;
    }
    return stack.top();
}

bool RPN::isOperator(char c) 
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::executeOperation(char op, int a, int b) 
{
    switch (op) 
	{
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) 
			{
                std::cerr << "Error" << std::endl;
        		return -1;
            }
            return a / b;
        default:
            std::cerr << "Error" << std::endl;
        	return -1;
    }
}