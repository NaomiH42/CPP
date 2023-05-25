/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixedConstr.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:57:48 by ehasalu           #+#    #+#             */
/*   Updated: 2023/05/25 12:36:33 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixedPointValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const i ) : _fixedPointValue(i << _fractBits)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float const f) : _fixedPointValue(roundf(f * (1 << _fractBits)))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &c )
{
	// std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = c.getRawBits();
}
