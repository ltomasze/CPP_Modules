/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:02:41 by ltomasze          #+#    #+#             */
/*   Updated: 2025/07/06 13:09:03 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iostream"

template <typename T, typename F>
void iter(T* array, size_t lenght, F function)
{
	for (size_t i = 0; i < lenght; ++i)
	{
		function(array[i]);
	}
}