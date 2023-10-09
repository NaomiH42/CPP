#include "Serializer.hpp"

int main(void)
{
	Data ptr;
	ptr.i = 5;
	ptr.c = 'a';
	std::cout << "Original i: " << ptr.i << std::endl;
	std::cout << "Original c: " << ptr.c << std::endl;
	uintptr_t raw = Serializer::serialize(&ptr);
	Data *ptr2 = Serializer::deserialize(raw);
	std::cout << "Seriliazed i: " << ptr2->i << std::endl;
	std::cout << "Seriliazed c: " << ptr2->c << std::endl;
}
