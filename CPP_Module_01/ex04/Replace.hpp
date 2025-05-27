/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:21:37 by ltomasze          #+#    #+#             */
/*   Updated: 2025/05/27 12:01:52 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

class Replace
{
	private:
		std::string _filename;
		std::string _s1;
		std::string _s2;
	public:
		Replace(const std::string& filename, const std::string& s1, const std::string& s2);
		~Replace();

		bool processFile() const;
};

#endif