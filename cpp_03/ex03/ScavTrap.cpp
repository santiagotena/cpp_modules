/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:13:29 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/22 23:13:30 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	_name = "Nameless";
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "A nameless ScavTrap has been assembled." << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_name = name;
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " has been assembled." << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &other): ClapTrap(other)
{
	*this = other;
	std::cout << "ScavTrap created from blueprint." << std::endl;
	return ;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_maxHitPoints = other._maxHitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "ScavTrap's copy and transfer of data completed." << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " has been disassembled." << std::endl;
	return ;
}

bool	ScavTrap::operator==(ScavTrap const &other) const
{
	if (_name == other._name &&
		_hitPoints == other._hitPoints &&
		_maxHitPoints == other._maxHitPoints &&
		_energyPoints == other._energyPoints &&
		_attackDamage == other._attackDamage)
		return (true);
	else
		return (false);
}

void	ScavTrap::attack(const std::string &target)
{
	if (!_isActionPossible())
		return ;
	_energyPoints -= 1;
	std::cout << "ScavTrap " << _name << " kicks " << target << " for " << \
	_attackDamage << " points of damage." << std::endl;
	return ;
}

void	ScavTrap::attackTarget(ClapTrap &target)
{
	if (!_isActionPossible())
		return ;
	_energyPoints -= 1;
	std::cout << "ScavTrap " << _name << " kicks " << target.getName() << \
	" for " << _attackDamage << " points of damage." << std::endl;
	target.takeDamage(_attackDamage);
	return ;
}

void	ScavTrap::attackTarget(ScavTrap &target)
{
	if (!_isActionPossible())
		return ;
	_energyPoints -= 1;
	std::cout << "ScavTrap " << _name << " kicks " << target._name << \
	" for " << _attackDamage << " points of damage." << std::endl;
	target.takeDamage(_attackDamage);
	return ;
}

void	ScavTrap::guardGate(void)
{
	if (!_isActionPossible())
		return ;
	std::cout << "ScavTrap " << _name << " has entered Gate Keeper Mode." << \
	std::endl;
	return ;
}