/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:10:05 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/16 22:19:13 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class Weapon {
	public:
		Weapon(void);
		~Weapon(void);

		void		setType(std::string type);
		std::string	&getType(void) const;

	private:
		std::string const _type;
};


#endif