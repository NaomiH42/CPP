#include <iostream>
#include "Phonebook.class.hpp"

void	ask_for_command(Phonebook book)
{
	std::string command;

	command = "";
	std::cout << "Enter a command: " << std::endl;
	std::cin >> command;
	if (command != "ADD" && command != "EXIT" && command != "SEARCH")
		ask_for_command(book);
	if (command == "ADD")
	{
		book.add_new();
		ask_for_command(book);
	}
	else if (command == "SEARCH")
	{
		book.search();
		ask_for_command(book);
	}
	else if (command == "EXIT")
		return ;
}

int	main(void)
{
	Phonebook	book;


	ask_for_command(book);
}
