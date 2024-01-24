#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	std::ifstream input;
	input.open(argv[1]);
	if (!input.good())
	{
		std::cerr << "Error: could not open file.\n";
		return (0);
	}
	BitcoinExchange ex;
	BitcoinExchange ex2 = ex;
	ex2.convert(input);

}
