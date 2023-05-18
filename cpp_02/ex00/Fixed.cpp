/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:27:51 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/18 11:06:37 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fixedPoint(0)
{
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(Fixed const &source)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = source;
}

Fixed	&Fixed::operator=(Fixed const &assign)
{
	std::cout << "Copy assignment operator called." << std::endl;
	_fixedPoint = assign.getRawBits();
	return(*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called." << std::endl;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called." << std::endl;
	_fixedPoint = raw;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return (_fixedPoint);
}
