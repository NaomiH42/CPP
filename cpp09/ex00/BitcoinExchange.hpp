#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(std::ifstream&);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& o);
		BitcoinExchange&operator=(const BitcoinExchange& o);

	private:
		std::map<std::string, int> _dat;

};

#endif
