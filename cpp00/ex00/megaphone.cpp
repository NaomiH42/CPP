/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:57:03 by ehasalu           #+#    #+#             */
/*   Updated: 2023/03/19 14:26:14 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	int	l;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE * " << std::endl;
	else
	{
		while (i < argc)
		{
			l = 0;
			while (argv[i][l])
			{
				std::cout << (char) toupper(argv[i][l]);
				l++;
			}
			i++;
		}
	}
	std::cout << std::endl;
}
