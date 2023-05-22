/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:10:53 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/22 22:33:01 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	{
		std::cout << "// HP TESTS //" << std::endl;
		FragTrap fedia("Fedia");

		fedia.highFivesGuys();
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
		FragTrap fedia("Fedia");
		FragTrap kiria("Kiria");
		ClapTrap yura("Yura");
		ClapTrap jora("Jora");
		
		fedia.highFivesGuys();
		std::cout << "No one gives a high five..." << std::endl;
		fedia.attackTarget(yura);
		fedia.attackTarget(jora);
		fedia.attackTarget(kiria);
		fedia.checkStatus();
		kiria.checkStatus();

		std::cout << "FragTrap Fedia fell of a cliff." << std::endl;
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
