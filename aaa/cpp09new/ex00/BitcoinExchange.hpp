#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits.h>
#include <iomanip>
#include <time.h>
#include <string.h>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& o);
		BitcoinExchange&operator=(const BitcoinExchange& o);
		void convert(std::ifstream&);

	private:
		std::map<std::string, float> _dat;
		bool checkDate(struct tm timeDate);
		bool checkNum(std::string value);

};

#endif
