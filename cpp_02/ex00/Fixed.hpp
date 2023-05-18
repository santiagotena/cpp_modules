/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:27:50 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/18 11:05:28 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const &source);
		Fixed &operator=(Fixed const &assign);
		~Fixed(void);
		
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		
	private:
		int					_fixedPoint;
		static const int	_fractionalBits = 8;
};

#endif