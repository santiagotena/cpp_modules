/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:10:08 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/17 00:21:58 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) :
		_name(name),
		_weapon(NULL)
{
	std::cout << this->_name << " has entered battle." << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << this->_name << " retreated." << std::endl;
	return ;
}

void	HumanB::attack(void) const
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << '.' << std::endl;
	else
		std::cout << this->_name << " attacks with closed fists." << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}