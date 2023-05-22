/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:15:43 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/22 21:56:44 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	{
		std::cout << "// HP TESTS //" << std::endl;
		ScavTrap fedia("Fedia");

		fedia.checkStatus();
		fedia.attack("Jora");
		fedia.takeDamage(5);
		fedia.checkStatus();
		fedia.beRepaired(4);
		fedia.checkStatus();
		
		fedia.takeDamage(120);
		
		fedia.checkStatus();

		fedia.attack("Jora");
		fedia.beRepaired(10);
	}
	{
		std::cout << std::string(50, '-') << std::endl;
		std::cout << "// GENERAL TESTS //" << std::endl;
		ScavTrap fedia("Fedia");
		ScavTrap kiria("Kiria");
		ClapTrap yura("Yura");
		ClapTrap jora("Jora");
		
		fedia.attackTarget(yura);
		fedia.attackTarget(jora);
		fedia.attackTarget(kiria);
		fedia.checkStatus();
		kiria.checkStatus();

		std::cout << "ScavTrap Fedia fell of a cliff." << std::endl;
		fedia.takeDamage(99);
		fedia.beRepaired(18);
		fedia.checkStatus();
		kiria.attackTarget(fedia);
		fedia.checkStatus();
		kiria.checkStatus();
	}	
	std::cout << std::string(50, '-') << std::endl;
	return (0);
}
