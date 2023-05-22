/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:23:18 by ehasalu           #+#    #+#             */
/*   Updated: 2023/05/22 10:09:09 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{

public:
	Fixed( void );
	Fixed( int const i);
	Fixed( const float f);
	Fixed( Fixed &c);
	~Fixed( void );
	Fixed &operator=(Fixed &rhs);
	Fixed &operator<<(Fixed &rhs);
	int	getRawBits( void ) const;
	void setRawBits( int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;

private:
	int _fixedPointValue;
	static const int _fractBits;

};

#endif
