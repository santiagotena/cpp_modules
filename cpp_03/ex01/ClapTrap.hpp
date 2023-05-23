/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:15:45 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/22 21:15:44 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hitPoints;
		int			_maxHitPoints;
		int			_energyPoints;
		int			_attackDamage;
		
		bool		_isActionPossible(void);

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &other);
		ClapTrap &operator=(ClapTrap const &other);
		~ClapTrap(void);

		bool	operator==(ClapTrap const &other) const;
		void	attack(const std::string &target);
		void	attackTarget(ClapTrap &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	checkStatus(void);

		std::string	getName(void) const;
};

#endif