/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:49 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/26 11:31:50 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {
    _type = "cure";
}

Cure::Cure(Cure const &other) : AMateria(other)
{
    *this = other;
}

Cure    &Cure::operator=(Cure const &other) {
    _type = other._type;
    return (*this);
}

Cure::~Cure() {};

AMateria    *Cure::clone() const {
    AMateria    *clone;

    clone = new Cure(*this);
    return (clone);
}

void    Cure::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
