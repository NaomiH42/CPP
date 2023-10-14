#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){};
BitcoinExchange::BitcoinExchange(std::ifstream& input)
{
	std::string line;
	std::string line2;
	int i = -1;
	while (std::getline(input, line, '|'))
	{
		std::string date = line;
		std::getline(input, line2, '\n');
		std::stringstream ss(line2);
		int value;
		ss >> value;
		i++;
		std::cout << i << ": " << line << "|" << value << "\n";
		_dat.insert(std::pair<std::string, int>(date, value));
	}
	// for (std::map<std::string, int>::iterator i = _dat.begin(); i != _dat.end(); i++)
	// 	std::cout << i->first << " | " << i->second << "\n";
};
BitcoinExchange::~BitcoinExchange(){};
BitcoinExchange::BitcoinExchange(const BitcoinExchange& o){*this = o;};
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& o){(void)o;return *this;};
