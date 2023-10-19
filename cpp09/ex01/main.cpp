#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	RPN test(argv[1]);
	if (!test.check())
	{
		std::cout << "bad input\n";
		return (0);
	}
	std::cout << "result: " <<  test.calculate() << std::endl;
}
