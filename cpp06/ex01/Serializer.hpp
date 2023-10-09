#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

typedef struct s_Data
{
	int		i;
	char	c;
}				Data;

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer&);
		Serializer& operator=(const Serializer &);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
