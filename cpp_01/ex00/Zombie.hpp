/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:24:03 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/17 20:57:55 by stena-he         ###   ########.fr       */
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

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif