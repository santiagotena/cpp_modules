/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:10:05 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/17 00:12:40 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class Weapon {
	public:
		Weapon(std::string type);
		~Weapon(void);

		void				setType(std::string type);
		const std::string	&getType(void) const;

	private:
		std::string _type;
};

#endif