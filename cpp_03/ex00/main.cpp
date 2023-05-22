/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:45:20 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/22 14:01:53 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	{
		std::cout << "// HP TESTS //" << std::endl;
		ClapTrap yura("Yura");

		yura.checkStatus();
		yura.attack("Jora");
		yura.takeDamage(5);
		yura.checkStatus();
		yura.beRepaired(4);
		yura.checkStatus();
		
		yura.takeDamage(5);
		yura.takeDamage(5);
		yura.takeDamage(5);
		
		yura.checkStatus();

		yura.attack("Jora");
		yura.beRepaired(10);
	}
	{
		std::cout << std::string(50, '-') << std::endl;
		std::cout << "// EP TESTS //" << std::endl;
		ClapTrap yura("Yura");
		ClapTrap jora("Jora");
		
		yura.attackTarget(jora);
		yura.attackTarget(jora);
		yura.attackTarget(jora);
		yura.attackTarget(jora);
		yura.attackTarget(jora);
		yura.checkStatus();

		std::cout << "ClapTrap Yura ran into a wall." << std::endl;
		yura.takeDamage(5);
		yura.beRepaired(1);
		yura.beRepaired(1);
		yura.checkStatus();
		yura.beRepaired(1);
		yura.beRepaired(1);
		yura.beRepaired(1);
		yura.checkStatus();
		
		yura.attackTarget(jora);
	}	
	std::cout << std::string(50, '-') << std::endl;
	return (0);
}