#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal* j = new Dog();
	Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;
	Cat *k = new Cat();
	Cat *l = new Cat(*k);
	l->compareCats(*k);
	delete k;
	delete l;

	const Animal * arr[4];
	for (int i = 0; i < 2; i++)
		arr[i] = new Dog();
	for (int i = 2; i < 4; i++)
		arr[i] = new Cat();
	for (int i = 0; i < 4; i++)
		delete arr[i];

	return 0;
}
