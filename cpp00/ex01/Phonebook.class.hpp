#include "Contact.class.hpp"

class Phonebook {

public:
	Contact	contacts[8];
	Phonebook(void);
	void 	add_new();
	void	ask_for_command();
	void	search(void);

};
