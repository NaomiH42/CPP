/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:10:12 by ehasalu           #+#    #+#             */
/*   Updated: 2023/05/21 14:28:01 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CPP
# define HARL_CPP

#include <iostream>

class Harl{


public:
	void complain( std::string level );

private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

};


#endif
