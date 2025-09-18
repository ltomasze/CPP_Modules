/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:56:24 by ltomasze          #+#    #+#             */
/*   Updated: 2025/09/18 12:26:39 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <sstream>

std::string trim(const std::string& str);
bool isValidDate(const std::string& date);
bool isValidValue(const std::string& value, std::string& errorMessage);
