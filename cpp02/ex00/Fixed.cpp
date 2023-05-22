/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:23:07 by ehasalu           #+#    #+#             */
/*   Updated: 2023/05/22 09:51:59 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int _fractBits = 8;

Fixed::Fixed( void ) : _nbValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed &c )
{
	std::cout << "Copy constructor called" << std::endl;
	this->_nbValue = c.getRawBits();
}

Fixed &Fixed::operator=( Fixed &rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_nbValue = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_nbValue);
}

void Fixed::setRawBits( int const raw)
{
	this->_nbValue = raw;
}
