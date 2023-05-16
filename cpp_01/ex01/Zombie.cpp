/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:22:00 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/16 15:00:07 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)  {
	std::cout << this->_name << " has raised from the dead!" << std::endl;
	return ;
}

Zombie::Zombie(void) {
	std::cout << "A zombie has raised from the dead!" << std::endl;
	return ;
}

Zombie::~Zombie(void) {
	if (this->_name.empty())
		std::cout << "A zombie has died another death." << std::endl;
	else
		std::cout << this->_name << " has died another death." << std::endl;
	return ;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
	return ;
}

void	Zombie::announce(void) const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::announceIndex(int index) const {
	std::cout << this->_name << " #" << index << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
