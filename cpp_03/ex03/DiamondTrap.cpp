/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:56:56 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/22 23:34:31 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void):
	_name("Nameless")
{
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_maxHitPoints = FragTrap::_maxHitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "A nameless DiamondTrap has been assembled." << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name):
	_name(name)
{
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_maxHitPoints = FragTrap::_maxHitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " has been assembled." << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other)
{
	*this = other;
	return ;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	ClapTrap::_name = _name + "_clap_name";
	_name = other._name;
	_hitPoints = other._hitPoints;
	_maxHitPoints = other._maxHitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << _name << " has been disassembled." << std::endl;
	return ;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << _name << ". Technically my name is: " << ClapTrap::_name << std::endl;
	return ;
}
