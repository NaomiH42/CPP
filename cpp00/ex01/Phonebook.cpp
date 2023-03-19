#include "Phonebook.hpp"

void	Phonebook::init(void)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		contacts[i].first_name = "";
		i++;
	}
}

void	Phonebook::add_new(void)
{
	int	i;

	i = 0;
	if (contacts[i].first_name != "" && i < 8)
		i++;
	if (i == 7)
		i = 0;
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

void	Phonebook::ask_for_command()
{
	std::string command;

	std::cout << "Enter a command: " << std::endl;
	std::cin >> command;
	if (command != "ADD" && command != "EXIT" && command != "SEARCH")
		ask_for_command();
	while (command != "EXIT")
	{
		if (command == "ADD")
			add_new();
		else if (command == "SEARCH")
			stuff;
		else if (command == "EXIT")
			exit (0);
		command = "";
		ask_for_command();
	}
}
