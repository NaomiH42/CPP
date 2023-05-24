/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:23:07 by ehasalu           #+#    #+#             */
/*   Updated: 2023/05/22 15:58:14 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

float Fixed::toFloat( void ) const
{
	return ((float)_fixedPointValue / (1 << _fractBits));
}

int	Fixed::toInt( void ) const
{
	return (_fixedPointValue >> _fractBits);
}

int Fixed::getRawBits( void ) const
{
	return (this->_fixedPointValue);
}

void Fixed::setRawBits( int const raw)
{
	this->_fixedPointValue = raw;
}

std::ostream &operator<<( std::ostream &out, Fixed const &i)
{
	out << i.toFloat();
	return (out);
}