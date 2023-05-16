/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:24:05 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/16 00:12:40 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {
	return ;
}

Zombie::~Zombie(void) {
	return ;
}

void	Zombie::announce(void) {
	std::cout << this->_name << ": " << "BraiiiiiiinnnzzzZ...";
}