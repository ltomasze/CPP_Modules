/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:09:32 by ltomasze          #+#    #+#             */
/*   Updated: 2025/05/17 18:03:17 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char **argv)
{
	if(argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if(s1.empty())
	{
		std::cerr << "Error: s1 cannot be an empty string." << std::endl;
		return (1); 
	}
	Replace replacer(filename, s1, s2);
	if (!replacer.processFile())
	{
		std::cerr << "Error: Failed to process file." << std::endl;
		return (1);
	}
	std::cout << "File processed successfully. Output: " << filename << ".replace" << std::endl;
	return (0);
}