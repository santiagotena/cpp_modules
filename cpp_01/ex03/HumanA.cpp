/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:10:06 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/17 00:17:04 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): 
		_name(name), 
		_weapon(weapon) 
{
	std::cout << this->_name << " has entered battle." << std::endl;
	return ;
}

HumanA::~HumanA(void) {
	std::cout << this->_name << " retreated." << std::endl;
	return ;
}

void	HumanA::attack(void) const {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << '.' << std::endl;
	return ;
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->_weapon = weapon;
	return ;
}