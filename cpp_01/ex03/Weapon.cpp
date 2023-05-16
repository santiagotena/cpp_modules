/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:10:04 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/16 22:21:56 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {
	return ;
}

Weapon::~Weapon(void) {
	return;
}

void	Weapon::setType(std::string type) {
	this->_type = type;
}