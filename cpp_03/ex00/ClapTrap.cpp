/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:45:24 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/22 14:02:39 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : 
					_hitPoints(10),
					_maxHitPoints(10),
					_energyPoints(10),
					_attackDamage(0)
{
	std::cout << "A nameless ClapTrap has been assembled." << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : 
					_name(name),
					_hitPoints(10),
					_maxHitPoints(10),
					_energyPoints(10),
					_attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " has been assembled." << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	*this = other;
	std::cout << "ClapTrap created from blueprint." << std::endl;
	return ;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "ClapTrap's copy and transfer of data completed." << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << _name << " has been disassembled." << std::endl;
	return ;
}

bool	ClapTrap::operator==(ClapTrap const &other) const
{
	if (_name == other._name &&
		_hitPoints == other._hitPoints &&
		_energyPoints == other._energyPoints &&
		_attackDamage == other._attackDamage)
		return (true);
	else
		return (false);
}

bool	ClapTrap::_isActionPossible(void)
{
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy left." << std::endl;
		return (false);
	}
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is KO." << std::endl;
		return (false);
	}
	return (true);
}

void	ClapTrap::attack(const std::string &target)
{
	if (!_isActionPossible())
		return ;
	_energyPoints -= 1;
	std::cout << "ClapTrap " << _name << " slaps " << target << " for " << \
	_attackDamage << " points of damage." << std::endl;
	return ;
}

void	ClapTrap::attackTarget(ClapTrap &target)
{
	if (!_isActionPossible())
		return ;
	_energyPoints -= 1;
	std::cout << "ClapTrap " << _name << " slaps " << target._name << \
	" for " << _attackDamage << " points of damage." << std::endl;
	target.takeDamage(_attackDamage);
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already KO." << std::endl;
		return ;
	}
	_hitPoints -= amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
	std::cout << "ClapTrap " << _name << " received " << amount << \
	" points of damage." << std::endl;
	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " has fainted." << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_isActionPossible())
		return ;
	_energyPoints -= 1;
	_hitPoints += amount;
	if (_hitPoints > _maxHitPoints)
		_hitPoints = _maxHitPoints;
	std::cout << "ClapTrap " << _name << " repairs itself. It recovered " << \
	amount << " hit points." << std::endl;
	return ;
}

void	ClapTrap::checkStatus(void)
{
	std::cout << _name << " Stats:" << std::endl;
	std::cout << "HP: " << _hitPoints << std::endl;
	std::cout << "EP: " << _energyPoints << std::endl;
	return ;
}
