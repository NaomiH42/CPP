/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:22:46 by ehasalu           #+#    #+#             */
/*   Updated: 2023/05/24 11:48:58 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed e;
	Fixed const b( 6 );
	Fixed const d( 0.5f );
	Fixed c( 42.42f );
	Fixed const a( 42.42f );

	if (b < c)
		std::cout << "b is smaller than c" << std::endl;
	if (c > b)
		std::cout << "c is bigger than b" << std::endl;
	if (c >= a)
		std::cout << "c is bigger or equal to a" << std::endl;
	if (b <= c)
		std::cout << "b is smaller or equal to c" << std::endl;
	if (c == a)
		std::cout << "c is equal to a" << std::endl;
	if (c != b)
		std::cout << "c is not equal to b" << std::endl;
	std::cout << (c + b) << std::endl;
	std::cout << (b - c) << std::endl;
	std::cout << (c * b) << std::endl;
	std::cout << (c / d) << std::endl;
	std::cout << c << std::endl;
	std::cout << ++c << std::endl;
	std::cout << ++e << std::endl;
	std::cout << e++ << std::endl;
	std::cout << e << std::endl;

	Fixed n;
	Fixed const m( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << n << std::endl;
	std::cout << ++n << std::endl;
	std::cout << n << std::endl;
	std::cout << n++ << std::endl;
	std::cout << n << std::endl;
	std::cout << m << std::endl;
	std::cout << Fixed::max( n, m ) << std::endl;

	return 0;
}
