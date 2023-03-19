#include "Contact.hpp"

class Phonebook {
public:
	Contact	contacts[8];
	void add_new();
	void	init(void);
	void	ask_for_command();
};
