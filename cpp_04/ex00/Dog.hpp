/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:05:40 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/24 01:05:41 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog(void);
    Dog(Dog const &other);
    Dog &operator=(Dog const &other);
    virtual ~Dog(void);

    bool            operator==(Dog const &other) const;
    virtual void    makeSound(void) const;
};

#endif