/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixedOverl.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:58:21 by ehasalu           #+#    #+#             */
/*   Updated: 2023/05/22 17:43:48 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed &Fixed::operator=( const Fixed &rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
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
	return ((float)(this->_fixedPointValue / rhs._fixedPointValue) / (1 << (_fractBits)));
}