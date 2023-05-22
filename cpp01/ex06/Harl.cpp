/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:10:04 by ehasalu           #+#    #+#             */
/*   Updated: 2023/05/21 14:58:23 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	void (Harl::*f[4])( void ) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = { "debug", "info", "warning", "error"};

	int i = 0;
	while (i < 4 && levels[i].compare(level))
		i++;
	switch (i)
	{
		case 0:
			(this->*(f[0]))();
		__attribute__((fallthrough));
		case 1:
			(this->*(f[1]))();
		__attribute__((fallthrough));
		case 2:
			(this->*(f[2]))();
		__attribute__((fallthrough));
		case 3:
			(this->*(f[3]))();
			break;
		default:
			break;
	}

}
