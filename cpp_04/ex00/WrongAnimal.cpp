/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:40:40 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/24 16:40:48 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Primordial WrongAnimal")
{
    std::cout << "A primordial wrong animal has been born." << std::endl;
    return;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
    *this = other;
    std::cout << "A primordial wrong animal has been cloned successfully." << std::endl;
    return;
}

WrongAnimal  &WrongAnimal::operator=(WrongAnimal const &other)
{
    _type = other._type;
    std::cout <<  "A primordial wrong animal has become as another." << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "A primordial wrong animal has been sent to the farm." << std::endl;
    return;
}

bool    WrongAnimal::operator==(WrongAnimal const &other) const
{
    return (_type == other._type);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "*A primordial and wrong sound goes off in the distance*" << std::endl;
    return;
}

std::string WrongAnimal::getType(void) const
{
    return (_type);
}
