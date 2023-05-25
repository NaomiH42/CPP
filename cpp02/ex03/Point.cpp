/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:26:00 by ehasalu           #+#    #+#             */
/*   Updated: 2023/05/25 17:36:36 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{

}

Point::~Point( void )
{

}

Point::Point( const float a, const float b) : _x(a), _y(b)
{

}

Point::Point( const Point &c ) : _x(c.getX()), _y(c.getY())
{
}

Point &Point::operator=( const Point &rhs )
{
	(void)rhs;
	return (*this);
}

Fixed	Point::getX( void ) const
{
	return (this->_x);
}

Fixed	Point::getY( void ) const
{
	return (this->_y);
}

Fixed	calcArea( Point const a, Point const b, Point const c)
{
	Fixed res;
	res = ((a.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - a.getY())) + (c.getX() * (a.getY() - b.getY()))) / 2;
	if (res < 1)
		res = res * -1;
	return (res);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed ABC = calcArea(a, b, c);
	Fixed PAB = calcArea(point, a, b);
	Fixed PBC = calcArea(point, b, c);
	Fixed PAC = calcArea(point, a, c);

	// std::cout << "ABC: " << ABC << std::endl;
	// std::cout << "PAB: " << PAB << std::endl;
	// std::cout << "PBC: " << PBC << std::endl;
	// std::cout << "PAC: " << PAC << std::endl;
	if (ABC == (PAB + PBC + PAC))
		return (true);
	return (false);
}
