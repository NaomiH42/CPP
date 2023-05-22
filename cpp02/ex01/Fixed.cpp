/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:23:07 by ehasalu           #+#    #+#             */
/*   Updated: 2023/05/22 11:29:12 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// const int _fractBits = 8;

Fixed::Fixed( void ) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const i ) : _fixedPointValue(i << _fractBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float const f) : _fixedPointValue(roundf(f * (1 << _fractBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
	return ((float)_fixedPointValue / (1 << _fractBits));
}

int	Fixed::toInt( void ) const
{
	return (_fixedPointValue >> _fractBits);
}

std::ostream &operator<<( std::ostream &out, Fixed const &i)
{
	out << i.toFloat();
	return (out);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &c )
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = c.getRawBits();
}	// std::cout << "getRawBits member function called" << std::endl;


Fixed &Fixed::operator=( const Fixed &rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void Fixed::setRawBits( int const raw)
{
	this->_fixedPointValue = raw;
}
