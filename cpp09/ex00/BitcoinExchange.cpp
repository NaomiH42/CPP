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
};

BitcoinExchange::~BitcoinExchange(){};
BitcoinExchange::BitcoinExchange(const BitcoinExchange& o){*this = o;};
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& o){(void)o;return *this;};


void BitcoinExchange::convert(std::ifstream& input)
{
	std::string line;

	std::getline(input, line, '\n');
	while (std::getline(input, line, '\n'))
	{
		struct tm timeDate;
		memset(&timeDate, 0, sizeof(struct tm));
		if (line.find('|') == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << "\n";
			continue;
		}
		std::string date = line.substr(0, line.find("|"));
		strptime(date.c_str(),"%Y-%m-%d", &timeDate);
		if (timeDate.tm_mon < 0 || timeDate.tm_mon > 11
		|| timeDate.tm_year + 1900 < 2009 || timeDate.tm_year + 1900 > 2023
		|| timeDate.tm_mday == 0)
		{
			std::cerr << "Error: bad date format => " << date << "\n";
			continue;
		}
		std::string value = line.substr(line.find("|") + 1);
		std::stringstream ss(value);
		double val;
		ss >> val;
		if (val > 1000 || val < 0)
		{
			if (val > 1000)
				std::cerr << "Error: too large number.\n";
			else if (val > 0)
				std::cerr << "Error: not a positive number.\n";
			continue;
		}
		for (std::map<std::string, float>::iterator i = _dat.begin(); i != _dat.end(); i++)
		{
			if (date <= i->first)
			{
				if (date < i->first)
					i--;
				std::cout << date << " => " << val << " = " << val * i->second << std::endl;
				break;
			}
		}
	}
};
