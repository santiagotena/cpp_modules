/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:55:34 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/22 22:55:47 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	_name = "Nameless";
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "A nameless FragTrap has been assembled." << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name)
{
	_name = name;
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " has been assembled." << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &other): ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap created from blueprint." << std::endl;
	return ;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_maxHitPoints = other._maxHitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "FragTrap's copy and transfer of data completed." << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " has been disassembled." << std::endl;
	return ;
}

bool	FragTrap::operator==(FragTrap const &other) const
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

void	FragTrap::attack(const std::string &target)
{
	if (!_isActionPossible())
		return ;
	_energyPoints -= 1;
	std::cout << "FragTrap " << _name << " punches " << target << " for " << \
	_attackDamage << " points of damage." << std::endl;
	return ;
}

void	FragTrap::attackTarget(ClapTrap &target)
{
	if (!_isActionPossible())
		return ;
	_energyPoints -= 1;
	std::cout << "FragTrap " << _name << " punches " << target.getName() << \
	" for " << _attackDamage << " points of damage." << std::endl;
	target.takeDamage(_attackDamage);
	return ;
}

void	FragTrap::attackTarget(FragTrap &target)
{
	if (!_isActionPossible())
		return ;
	_energyPoints -= 1;
	std::cout << "FragTrap " << _name << " punches " << target._name << \
	" for " << _attackDamage << " points of damage." << std::endl;
	target.takeDamage(_attackDamage);
	return ;
}

void	FragTrap::highFivesGuys(void)
{
	if (!_isActionPossible())
		return ;
	std::cout << "FragTrap " << _name << " is requesting a high five." << \
	std::endl;
	return ;
}
