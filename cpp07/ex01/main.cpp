#include "iter.hpp"

int main(void)
{
	int arr[5] = {40, 2, 31, 231, 68};
	std::cout << "Array before: ";
	for (int i = 0; i < 5; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	::iter(arr, 5, incr);
	std::cout << "Array after: ";
	for (int i = 0; i < 5; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	double arr2[5] = {40.5, 2.2, 31.1, 231.7, 68.8};
	std::cout << "Array before: ";
	for (int i = 0; i < 5; i++)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;
	::iter(arr2, 5, incr);
	std::cout << "Array after: ";
	for (int i = 0; i < 5; i++)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;

	char arr3[5] = {'u', 't', 'f', 'B', 'a'};
	std::cout << "Array before: ";
	for (int i = 0; i < 5; i++)
		std::cout << arr3[i] << " ";
	std::cout << std::endl;
	::iter(arr3, 5, incr);
	std::cout << "Array after: ";
	for (int i = 0; i < 5; i++)
		std::cout << arr3[i] << " ";

}
