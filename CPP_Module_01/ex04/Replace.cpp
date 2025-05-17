/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:21:24 by ltomasze          #+#    #+#             */
/*   Updated: 2025/05/17 16:42:19 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(const std::string& filename, const std::string& s1, const std:: string& s2)
	: _filename(filename), _s1(s1), _s2(s2) {}

Replace::~Replace() {}

bool Replace::processFile() const
{
	
}
