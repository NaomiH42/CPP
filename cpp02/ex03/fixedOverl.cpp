/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixedOverl.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:58:21 by ehasalu           #+#    #+#             */
/*   Updated: 2023/05/25 12:36:39 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed &Fixed::operator=( const Fixed &rhs )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

bool Fixed::operator>( const Fixed &rhs ) const
{
	if (this->_fixedPointValue > rhs._fixedPointValue)
		return (true);
	return (false);
}

bool Fixed::operator<( const Fixed &rhs ) const
{
	if (this->_fixedPointValue < rhs._fixedPointValue)
		return (true);
	return (false);
}

bool Fixed::operator>=( const Fixed &rhs ) const
{
	if (this->_fixedPointValue >= rhs._fixedPointValue)
		return (true);
	return (false);
}

bool Fixed::operator<=( const Fixed &rhs ) const
{
	if (this->_fixedPointValue <= rhs._fixedPointValue)
		return (true);
	return (false);
}

bool Fixed::operator==( const Fixed &rhs ) const
{
	if (this->_fixedPointValue == rhs._fixedPointValue)
		return (true);
	return (false);
}

bool Fixed::operator!=( const Fixed &rhs ) const
{
	if (this->_fixedPointValue != rhs._fixedPointValue)
		return (true);
	return (false);
}

Fixed Fixed::operator+( const Fixed &rhs) const
{
	return ((float)(this->_fixedPointValue + rhs._fixedPointValue) / (1 << _fractBits));
}

Fixed Fixed::operator-( const Fixed &rhs) const
{
	return ((float)(this->_fixedPointValue - rhs._fixedPointValue) / (1 << _fractBits));
}

Fixed Fixed::operator*( const Fixed &rhs) const
{
	return ((float)(this->_fixedPointValue * rhs._fixedPointValue) / (1 << (_fractBits * 2)));
}

Fixed Fixed::operator/( const Fixed &rhs) const
{
	return ((float)(this->_fixedPointValue / rhs._fixedPointValue));
}

Fixed &Fixed::operator++( void )
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator++( int )
{
	Fixed temp;
	temp = *this;
	this->_fixedPointValue++;
	return (temp);
}

Fixed &Fixed::operator--( void )
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--( int )
{
	Fixed temp;
	temp = *this;
	this->_fixedPointValue--;
	return (temp);
}

Fixed &Fixed::min( Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed Fixed::min( const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed &Fixed::max( Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed Fixed::max( const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
