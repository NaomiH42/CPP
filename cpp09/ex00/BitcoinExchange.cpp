#include "BitcoinExchange.hpp"

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
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& o)
{
	for(std::map<std::string, float>::const_iterator it = o._dat.begin(); it != o._dat.end(); it++)
	{
		this->_dat.insert(std::pair<std::string, float>(it->first, it->second));
	}
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& o)
{
	if (this != &o)
	{
		for(std::map<std::string, float>::const_iterator it = o._dat.begin(); it != o._dat.end(); it++)
		{
			this->_dat.insert(std::pair<std::string, float>(it->first, it->second));
		}
	}
	return *this;
}

bool BitcoinExchange::checkDate(struct tm timeDate)
{
	int month = timeDate.tm_mon + 1;
	int day = timeDate.tm_mday;
	int year = timeDate.tm_year + 1900;
	if (month < 1 || month > 12 || year < 2009 || year >= 2023 || day < 1)
		return (false);
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8
		|| month == 10 || month == 12) && day > 31)
		return (false);
	if (month == 2 && (day > 28 || (day > 29 && (year == 2012 || year == 2016 || year == 2020))))
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	return (true);
}

bool BitcoinExchange::checkNum(std::string value)
{
	for (int i = 0; value[i]; i++)
	{
		if (value[i] < '0' || value[i] > '9')
			return (false);
	}
	return (true);
}

void BitcoinExchange::convert(std::ifstream& input)
{
	std::string line;

	std::getline(input, line, '\n');
	if (line != "date | value")
	{
		std::cerr << "Make the first line date | value pls\n";
		return ;
	}
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
		if (timeDate.tm_year + 1900 == 2023)
		{
			std::cerr << "Error: I decided to limit the database until 2022 :) => " << date << "\n";
			continue;
		}
		if (!checkDate(timeDate))
		{
			std::cerr << "Error: bad date => " << date << "\n";
			continue;
		}
		std::string value = line.substr(line.find("|") + 1);
		value.erase(0, value.find_first_not_of(" "));
		if (!checkNum(value))
		{
			std::cerr << "Value containts non numerical values\n";
			continue;
		}
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
				{
					if (i == _dat.begin())
					{
						std::cout << "Error: date before database => " << date << "\n";
						break;
					}
					i--;
				}
				std::cout << date << " => " << val << " = " << val * i->second << std::endl;
				break;
			}
		}
	}
};
