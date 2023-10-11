#include "Span.hpp"

int main(void)
{
	Span a(5);
	try
	{
		std::cout << a.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	a.addNumber(5);
	try
	{
		std::cout << a.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	for (int i = 42; i < 80; i++)
	{
		try
		{
			a.addNumber(i);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	try
	{
		std::cout << a.shortestSpan() << std::endl;
		std::cout << a.longestSpan() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Span b(20000);
	srand(time(NULL));
	for (int i = 0; i < 20000; i++)
	{
		try
		{
			b.addNumber(rand());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	try
	{
		std::cout << b.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << b.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		b.addNumber(rand());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
// int main(void)
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// }
