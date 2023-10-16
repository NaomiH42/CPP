#include "BitcoinExchange.hpp"

// BitcoinExchange::BitcoinExchange(){};
BitcoinExchange::BitcoinExchange()
{
	std::string line;

	std::ifstream database;
	database.open("data.csv");
	std::getline(database, line, '\n');
	while (std::getline(database, line, '\n'))
	{
		std::string date = line.substr(0, line.find(","));
		std::string value = line.substr(line.find(",") + 1);
		std::stringstream ss(value);
		float val;
		ss >> val;
		_dat.insert(std::pair<std::string, float>(date, val));
	}
	std::cout << std::setprecision(2) << std::fixed;
	for (std::map<std::string, float>::iterator i = _dat.begin(); i != _dat.end(); i++)
		std::cout << i->first << " | " << i->second << "\n";
};
BitcoinExchange::~BitcoinExchange(){};
BitcoinExchange::BitcoinExchange(const BitcoinExchange& o){*this = o;};
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& o){(void)o;return *this;};


void BitcoinExchange::convert(std::ifstream& input)
{
	std::string line;

	while (std::getline(database, line, '\n'))
	{
		if (line.find('|') == std::string::npos)
			continue;
		std::string date = line.substr(0, line.find("|"));
		std::string value = line.substr(line.find("|") + 1);
		std::stringstream ss(value);
		float val;
		ss >> val;
		if (val >= 1000 || val <= 0)
			continue;
		_dat.insert(std::pair<std::string, float>(date, val));
	}
	for (std::map<std::string, float>::iterator i = _dat.begin(); i != _dat.end(); i++)
		std::cout << i->first << " | " << i->second << "\n";
};
