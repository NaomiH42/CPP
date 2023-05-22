/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:23:18 by ehasalu           #+#    #+#             */
/*   Updated: 2023/05/22 17:38:07 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{

public:
	Fixed( void );
	Fixed( const int i);
	Fixed( const float f);
	Fixed( const Fixed &c);
	~Fixed( void );

	Fixed &operator=( const Fixed &rhs );
	bool operator>( const Fixed &rhs ) const;
	bool operator<( const Fixed &rhs ) const;
	bool operator>=( const Fixed &rhs ) const;
	bool operator<=( const Fixed &rhs ) const;
	bool operator==( const Fixed &rhs ) const;
	bool operator!=( const Fixed &rhs ) const;

	Fixed operator+( const Fixed &rhs ) const;
	Fixed operator-( const Fixed &rhs ) const;
	Fixed operator*( const Fixed &rhs ) const;
	Fixed operator/( const Fixed &rhs ) const;

	int	getRawBits( void ) const;
	void setRawBits( int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;

private:
	int _fixedPointValue;
	static const int _fractBits = 8;

};
std::ostream &operator<<( std::ostream &out, Fixed const &i);

#endif
