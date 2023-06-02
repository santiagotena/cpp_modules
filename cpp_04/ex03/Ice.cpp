/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:51 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/26 11:31:52 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() {
    _type = "ice";
}

Ice::Ice(const Ice &other): AMateria(other)
{
    *this = other;
}

Ice &Ice::operator=(Ice const &other) {
    _type = other._type;
    return (*this);
}

Ice::~Ice() {};

AMateria    *Ice::clone() const {
    AMateria    *clone;

    clone = new Ice(*this);
    return (clone);
}

void    Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
