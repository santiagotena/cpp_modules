/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:27:51 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/19 15:46:45 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fixedPoint(0)
{
	std::cout << "Default constructor called." << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = other;
	return ;
}

Fixed	&Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	this->_fixedPoint = other.getRawBits();
	return(*this) ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called." << std::endl;
	return ;
}

 bool Fixed::operator==(Fixed const &other) const {
		return (this->_fixedPoint == other.getRawBits());
    }

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called." << std::endl;
	this->_fixedPoint = raw;
	return ;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return (this->_fixedPoint);
}
