/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:22:46 by ehasalu           #+#    #+#             */
/*   Updated: 2023/09/07 15:55:36 by ehasalu          ###   ########.fr       */
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

	Point a2(0, 0);
	Point b2(10, 30);
	Point c2(20, 0);
	Point p2(11, 15);

	if(bsp(a, b, c, p))
		std::cout << "Point is inside the triangle!" << std::endl;
	else
		std::cout << "Point is not inside the triangle!" << std::endl;
	if(bsp(a2, b2, c2, p2))
		std::cout << "Point 2 is inside the triangle 2!" << std::endl;
	else
		std::cout << "Point 2 is not inside the triangle 2!" << std::endl;
	return 0;
}
