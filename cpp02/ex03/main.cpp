/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:22:46 by ehasalu           #+#    #+#             */
/*   Updated: 2023/05/25 12:42:19 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void )
{
	Point a(0, 0);
	Point b(10, 30);
	Point c(20, 0);
	Point p(30, 15);

	if(bsp(a, b, c, p))
		std::cout << "Point is inside the triangle!" << std::endl;
	else
		std::cout << "Point is not inside the triangle!" << std::endl;
	return 0;
}
