/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:44 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/26 11:31:45 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("base materia.") {};

AMateria::AMateria(std::string const &type) : _type(type) {};

AMateria::AMateria(AMateria const &other) {
    *this = other;
}

AMateria    &AMateria::operator=(const AMateria &other) {
    _type = other._type;
    return (*this);
}

AMateria::~AMateria() {};

std::string const   &AMateria::getType() const {
    return (_type);
}

void    AMateria::use(ICharacter &target) {
    std::cout << "A base materia was used against " << target.getName() << ". No effect." << std::endl;
}