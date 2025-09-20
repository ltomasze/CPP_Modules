/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:31:58 by ltomasze          #+#    #+#             */
/*   Updated: 2025/09/20 18:26:20 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stack>
#include <iostream>
#include <cctype> //for isspace

class RPN
{
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		int processExpression(const std::string& expression) const;

	private:
		static bool isOperator(char c);
		static int executeOperation(char op, int a, int b);
};
