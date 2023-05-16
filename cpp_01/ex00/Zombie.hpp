/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:24:03 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/16 13:08:41 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class	Zombie {
	public:
		Zombie(std::string name);
		~Zombie(void);
	
		void	announce(void) const;
	
	private:
		std::string const	_name;
};

Zombie	*newZombie(std::string);
void	randomChump(std::string);

#endif