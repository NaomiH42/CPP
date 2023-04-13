#include "Phonebook.class.hpp"
#include <iomanip>
#include <cstring>

Phonebook::Phonebook(void)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		contacts[i].first_name = "";
		contacts[i].index = 200;
		i++;
	}
	return ;
}

void	Phonebook::search(void)
{
	int	i;
	int	l;

	i = 0;
	while (i < 8)
	{
		l = 0;
		while (l < 8)
		{
			if (contacts[l].index == i)
			{
				std::cout << std::right << std::setw(10) << i << '|';
				if ((contacts[l].first_name).length() > 10)
					std::cout << std::right << std::setw(10) << (contacts[l].first_name).substr(0, 9) + '.' << "|";
				else
					std::cout << std::right << std::setw(10) << contacts[l].first_name << '|';
				if ((contacts[l].last_name).length() > 10)
					std::cout << std::right << std::setw(10) << (contacts[l].last_name).substr(0, 9) + '.' << "|";
				else
					std::cout << std::right << std::setw(10) << contacts[l].last_name << '|';
				if ((contacts[l].nickname).length() > 10)
					std::cout << std::right << std::setw(10) << (contacts[l].nickname).substr(0, 9) + '.' << std::endl;
				else
					std::cout << std::right << std::setw(10) << contacts[l].nickname << std::endl;
				std::cout << std::right << std::setw(10) << contacts[l].index << std::endl;
			}
			l++;
		}
		i++;
	}
}

void	Phonebook::add_new(void)
{
	int	i;

	i = 0;
	while (contacts[i].first_name != "" && i < 8)
	{
		contacts[i].index++;
		i++;
	}
	contacts[i].index = i - 1;
	if (i == 8)
	{
		i = 0;
		while (i < 8)
		{
			contacts[i].index++;
			i++;
		}
		i = 0;
		while (contacts[i].index != 8)
			i++;
		contacts[i].index = 0;
	}
	std::cout << "First name: " << std::endl;
	std::cin >> contacts[i].first_name;
	std::cout << "Last Name: " << std::endl;
	std::cin >> contacts[i].last_name;
	std::cout << "Nickname: " << std::endl;
	std::cin >> contacts[i].nickname;
	std::cout << "Phone Number: " << std::endl;
	std::cin >> contacts[i].phone_number;
	std::cout << "Darkest Secret: " << std::endl;
	std::cin >> contacts[i].darkest_secret;
}