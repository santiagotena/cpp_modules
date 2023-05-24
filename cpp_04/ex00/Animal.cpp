/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:05:37 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/24 01:05:38 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Primordial Animal")
{
    std::cout << "A primordial animal has been born." << std::endl;
    return;
}

Animal::Animal(Animal const &other)
{
    *this = other;
    std::cout << "A primordial animal has been cloned successfully." << std::endl;
    return;
}

Animal  &Animal::operator=(Animal const &other)
{
    _type = other._type;
    std::cout <<  "A primordial animal has become as another." << std::endl;
    return (*this);
}

Animal::~Animal(void)
{
    std::cout << "A primordial animal has been sent to the farm." << std::endl;
    return;
}

bool    Animal::operator==(Animal const &other) const
{
    return (_type == other._type);
}

void    Animal::makeSound(void)
{
    std::cout << "*A primordial sound goes off in the distance*" << std::endl;
    return;
}

