/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:21:59 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/16 15:01:15 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class	Zombie {
	public:
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);
	
		void	setName(std::string name);
		void	announce(void) const;
		void	announceIndex(int index) const;
	
	private:
		std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif