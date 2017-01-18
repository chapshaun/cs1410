//Chapter 10: Pointers

/*
we want the address of the memory locations

address operator & (reference opperator)

char* ptr; = pointer, it doesn't store a char, it stores a memory address

short* ptr;
*/



{
#include <iostream>

int main()
{
	char letter = 'a';
	short value = 100;
	float amount = 200.2;

	float amount2 = 300.4;

	float* ptr;

	//std::cout << letter << std::endl;
	//std::cout << &letter << std::endl;

	//std::cout << value << std::endl;
	//std::cout << &value << std::endl;

	//std::cout << amount << std::endl;
	//std::cout << &amount << std::endl;

	ptr = &amount;
	std::cout << ptr << std::endl;

	std::cout << amount << std::endl;
	std::cout << *ptr << std::endl; // dereference

	*ptr = 400; // dereference the value, and place the value into it

	std::cout << amount << std::endl;
	std::cout << *ptr << std::endl; // dereference


	ptr = &amount2;

	std::cout << *ptr << std::endl;
	std::cout << amount << std::endl;
	std::cout << amount2 << std::endl;

	return 0;
}
}
