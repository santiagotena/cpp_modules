/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:24:03 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/16 00:01:01 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Zombie {
	public:

		Zombie(void);
		~Zombie(void);
	
		void	announce(void);
	
	private:
		std::string const	_name;
};