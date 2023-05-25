/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:12:51 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/26 00:12:52 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Primordial Animal")
{
    std::cout << "An animal has come to be." << std::endl;
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
    std::cout << "The animal has ceased to exist." << std::endl;
    return;
}

bool    Animal::operator==(Animal const &other) const
{
    return (_type == other._type);
}

void    Animal::makeSound(void) const
{
    std::cout << "*A primordial sound goes off in the distance*" << std::endl;
    return;
}

std::string Animal::getType(void) const
{
    return (_type);
}
