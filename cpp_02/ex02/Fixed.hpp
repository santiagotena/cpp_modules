/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:31:17 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/20 13:02:11 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed 
{
	public:
		Fixed(void);
		Fixed(int const number);
		Fixed(float const number);
		Fixed(Fixed const &other);
		Fixed &operator=(Fixed const &other);
		~Fixed(void);
		
		bool	operator>(Fixed const &other) const;
		bool	operator<(Fixed const &other) const;
		bool	operator>=(Fixed const &other) const;
		bool	operator<=(Fixed const &other) const;
		bool	operator==(Fixed const &other) const;
		bool	operator!=(Fixed const &other) const;
		
		Fixed	operator+(Fixed const &other) const;///
		Fixed	operator-(Fixed const &other) const;
		Fixed	operator*(Fixed const &other) const;
		Fixed	operator/(Fixed const &other) const;
		
		Fixed	operator++(int number);
		Fixed	operator++(void);
		Fixed	operator--(int number);
		Fixed	operator--(void);

		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed const &max(Fixed const &a, Fixed const &b);
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed const &min(Fixed const &a, Fixed const &b);
		
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		float	toFloat(void) const;
		int		toInt(void) const;
		
	private:
		int					_fixedPoint;
		static const int	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &output, Fixed const &input);

#endif