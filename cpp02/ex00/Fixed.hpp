/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:23:18 by ehasalu           #+#    #+#             */
/*   Updated: 2023/09/07 15:49:31 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{

public:
	Fixed( void );
	~Fixed( void );
	Fixed( Fixed &c);
	Fixed &operator=(Fixed &c);
	int	getRawBits( void ) const;
	void setRawBits( int const raw);

private:
	int _nbValue;
	static const int _fractBits = 8;

};

#endif
