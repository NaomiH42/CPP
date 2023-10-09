#include "TheStuff.hpp"

int main(void)
{
	Base *ran;
	ran = generate();
	identify(ran);
	Base& ref = *ran;
	identify(ref);
}
