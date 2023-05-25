/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:08:02 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/25 10:08:03 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    _type = "Dog";
    std::cout << "A dog has been born." << std::endl;
    _brain = new Brain();
    return;
}

Dog::Dog(Dog const &other): Animal()
{
    _brain = new Brain();
    *this = other;
    std::cout << "A dog has been cloned successfully." << std::endl;
    return;
}

Dog &Dog::operator=(Dog const &other)
{
    _type = other._type;
    *_brain = *other._brain;
    std::cout << "A dog has become as another." << std::endl;
    return (*this);
}

Dog::~Dog(void)
{
    delete _brain;
    std::cout << "A dog has been sent to the farm." << std::endl;
    return;
}

bool    Dog::operator==(Dog const &other) const
{
    return (_type == other._type);
}

void    Dog::makeSound() const
{
    std::cout << "*Woof* *Woof*" << std::endl;
    return;
}
