#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{

public:
	Point( void );
	Point( const float a, const float b);
	~Point( void );
	Point( const Point &c);
	Point &operator=( const Point &c );

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;

private:
	const Fixed _x;
	const Fixed _y;
	int	_comp;

};

#endif

bool bsp( Point const a, Point const b, Point const c, Point const point);
Fixed	calcArea( Point const a, Point const b, Point const c);
