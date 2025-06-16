/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:10:05 by ltomasze          #+#    #+#             */
/*   Updated: 2025/06/15 18:13:11 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
        Brain* brain;
    public:
        Cat();
        Cat(const Cat& sourceObj);
        Cat& operator=(const Cat& sourceObj);
        virtual ~Cat();

        void makeSound() const;
};

#endif
