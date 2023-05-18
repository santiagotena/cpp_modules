/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:27:50 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/18 09:10:02 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed & operator=(const Fixed &assign);
		~Fixed();
		
		void	setRawBits(const int raw);
		int		getRawBits() const;
		
	private:
		int					_fixed_point;
		static const int	_fract_bits = 8;
};

#endif