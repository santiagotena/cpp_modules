/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:41:12 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/24 16:41:13 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    _type = "WrongCat";
    std::cout << "A cat has been born." << std::endl;
    return;
}

WrongCat::WrongCat(WrongCat const &other)
{
    *this = other;
    std::cout << "A cat has been cloned successfully." << std::endl;
    return;
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
    _type = other._type;
    std::cout << "A cat has become as another." << std::endl;
    return (*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "A cat has been sent to the farm." << std::endl;
    return;
}

bool    WrongCat::operator==(WrongCat const &other) const
{
    return (_type == other._type);
}

void    WrongCat::makeSound() const
{
    std::cout << "*Meow* *Meow*" << std::endl;
    return;
}
