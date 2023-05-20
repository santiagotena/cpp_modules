/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:28:58 by stena-he          #+#    #+#             */
/*   Updated: 2023/05/20 11:07:38 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fixedPoint(0)
{
	std::cout << "Default constructor called." << std::endl;
	return ;
}

Fixed::Fixed(int const number): 
	_fixedPoint(number << _fractionalBits) 
{
	std::cout << "Int constructor called." << std::endl;
	return ;
}

Fixed::Fixed(float const number):
	_fixedPoint(roundf(number * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called." << std::endl;
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
	this->_fixedPoint = other._fixedPoint;
	return (*this) ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called." << std::endl;
	return ;
}

 bool Fixed::operator==(Fixed const &other) const {
		return (this->_fixedPoint == other._fixedPoint);
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

float	Fixed::toFloat(void) const
{
	return (float)this->_fixedPoint / (float)(1 << this->_fractionalBits);
}

int		Fixed::toInt(void) const
{
	return (int)(this->_fixedPoint >> this->_fractionalBits);
}

std::ostream	&operator<<(std::ostream &output, Fixed const &input)
{
	output << input.toFloat();
	return output;
}
