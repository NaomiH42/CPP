/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:22:46 by ehasalu           #+#    #+#             */
/*   Updated: 2023/05/22 17:42:37 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed const b( 10 );
	Fixed const c( 42.42f );
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
	std::cout << (c / b) << std::endl;


return 0;
}
