/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:56:24 by ltomasze          #+#    #+#             */
/*   Updated: 2025/09/18 17:31:42 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <map>
#include <sstream>

std::string trim(const std::string& str);
bool isValidDate(const std::string& date);
bool isValidValue(const std::string& value, std::string& errorMessage);
std::map<std::string, double> loadExchangeRates(const std::string& filename);
double getExchangeRate(const std::map<std::string, double>& exchangeRates, const std::string& date);
