/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:55:36 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/22 23:14:06 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const &other);
		FragTrap &operator=(FragTrap const &other);
		~FragTrap(void);

		bool	operator==(FragTrap const &other) const;
		void	attack(const std::string &target);
		void	attackTarget(ClapTrap &target);
		void	attackTarget(FragTrap &target);
		void	highFivesGuys(void);
};

#endif