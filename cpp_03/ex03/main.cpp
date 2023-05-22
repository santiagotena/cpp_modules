/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:55:37 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/22 23:48:59 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	{
		std::cout << "// TESTS //" << std::endl;
		DiamondTrap	marie("Marie");

		marie.attack("Jora");
		marie.takeDamage(50);
		marie.beRepaired(10);
		marie.highFivesGuys();
		marie.whoAmI();
		marie.guardGate();
		marie.takeDamage(50);
		marie.takeDamage(50);
		marie.attack("Jora");
	}
	std::cout << std::string(50, '-') << std::endl;
	return (0);
}
