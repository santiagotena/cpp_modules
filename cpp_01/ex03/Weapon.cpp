/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:10:04 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/17 00:23:14 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
	std::cout << "A " << this->_type << " is available." << std::endl;
	return ;
}

Weapon::~Weapon(void) {
	std::cout << "The " << this->_type << " is discarded." << std::endl;
	return;
}

void	Weapon::setType(std::string type) {
	this->_type = type;
}

const std::string	&Weapon::getType(void) const
{
	const std::string	&typeRef = this->_type;
	return (typeRef);
}
