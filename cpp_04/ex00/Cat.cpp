/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:05:41 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/24 01:05:42 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    _type = "Cat";
    std::cout << "A cat has been born." << std::endl;
    return;
}

Cat::Cat(Cat const &other)
{
    *this = other;
    std::cout << "A cat has been cloned successfully." << std::endl;
    return;
}

Cat &Cat::operator=(Cat const &other)
{
    _type = other._type;
    std::cout << "A cat has become as another." << std::endl;
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "A cat has been sent to the farm." << std::endl;
    return;
}

bool    Cat::operator==(Cat const &other) const
{
    return (_type == other._type);
}

void    Cat::makeSound()
{
    std::cout << "*Meow* *Meow*" << std::endl;
    return;
}
