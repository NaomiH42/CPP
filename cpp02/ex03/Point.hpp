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
	Point &operator=(Point &c);

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;

private:
	const Fixed _x;
	const Fixed _y;

};

#endif
