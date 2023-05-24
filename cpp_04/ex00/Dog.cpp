/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:05:39 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/24 01:05:40 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : _type("Dog")
{
    std::cout << "A dog has been born." << std::endl;
    return;
}

Dog::Dog(Dog const &other)
{
    *this = other;
    std::cout << "A dog has been cloned successfully." << std::endl;
    return;
}

Dog &Dog::operator=(Dog const &other)
{
    _type = other._type;
    std::cout << "A dog has become as another." << std::endl;
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "A dog has been sent to the farm" << std::endl;
    return;
}

bool    Dog::operator==(Dog const &other) const
{
    return (_type == other._type);
}

void    Dog::makeSound()
{
    std::cout << "*Woof* *Woof*" << std::endl;
    return;
}
