#include "TheStuff.hpp"

Base*
generate(void)
{
	Base* new_c;
	srand(time(0));
	int	r = rand() % 90;
	if (r < 30)
	{
		std::cout << "Created A" << std::endl;
		new_c = new A();
	}
	else if (r < 60)
	{
		std::cout << "Created B" << std::endl;
		new_c = new B();
	}
	else
	{
		std::cout << "Created C" << std::endl;
		new_c = new C();
	}
	return (new_c);
}

void
identify(Base *p)
{
	Base *t = dynamic_cast<A*>(p);
	Base *t2 = dynamic_cast<B*>(p);
	Base *t3 = dynamic_cast<C*>(p);
	if (t != NULL)
		std::cout << "Pointer is A" << std::endl;
	else if (t2 != NULL)
		std::cout << "Pointer is B" << std::endl;
	else if (t3 != NULL)
		std::cout << "Pointer is C" << std::endl;
}

void
identify(Base& p)
{
	try
	{
		Base& t = dynamic_cast<A&>(p);
		std::cout << "Ref is A" << std::endl;
		t = t;
	}
	catch (const std::exception& e)
	{}
	try
	{
		Base& t2 = dynamic_cast<B&>(p);
		std::cout << "Ref is B" << std::endl;
		t2 = t2;
	}
	catch (const std::exception& e)
	{}
	try
	{
		Base& t3 = dynamic_cast<C&>(p);
		std::cout << "Ref is C" << std::endl;
		t3 = t3;
	}
	catch (const std::exception& e)
	{}
}
