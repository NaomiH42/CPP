#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits.h>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 42

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& o);
		ScalarConverter& operator=(const ScalarConverter& rhs);
		static void	toChar(std::string);
		static void		toInt(std::string);
		static void	toFloat(std::string);
		static void	toDouble(std::string);
		static int doBsNan(std::string);
		static int doBsInf(std::string);
		static int bsCheck(std::string);

		// int		_type;
		// int		convertToInt();
		// char	convertToChar()
		void	decideType();
	public:
		static void convert(std::string);
};

#endif
