/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:24:02 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/16 12:53:41 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	*undead;
	
	undead = newZombie("Zack");
	undead->announce();
	randomChump("Zoey");
	delete undead;
	return (0);
}
