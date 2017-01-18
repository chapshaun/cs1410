//Pointers continued

const int values[] = {1, 2, 3, 4};
//wouldn't be able to do this
values[4] = 6;

const int* pValues = values;

//you couldn't
pValues[4] = 6;

//const pointers to const values

//Code
{
	#include <iostream>
#include <iomanip>

void displayPayRates(const double* rates, unsigned int size)
{
	std::cout << std::setprecision(2) << std::fixed << std::showpoint;
	for (unsigned int payRate = 0; payRate < size; payRate++)
	{
		std::cout << "pay rate is $" << *(rates + payRate) << std::endl;
	}
}



int main()
{
	const unsigned int NUM_PAYRATES = 6;
	const double payRates[] = { 18, 55, 17, 45, 12, 85, 14, 97, 10, 35, 18, 89 };
	displayPayRates(payRates, NUM_PAYRATES);

	return 0;
}
}

//You can cast and change a const variable
{
#include <iostream>
#include <iomanip>

void displayPayRates(double* rates, unsigned int size)
{
	rates[0] = 1.00;
	std::cout << std::setprecision(2) << std::fixed << std::showpoint;
	for (unsigned int payRate = 0; payRate < size; payRate++)
	{
		std::cout << "pay rate is $" << *(rates + payRate) << std::endl;
	}
}



int main()
{
	const unsigned int NUM_PAYRATES = 6;
	const double payRates[] = { 18, 55, 17, 45, 12, 85, 14, 97, 10, 35, 18, 89 };
	displayPayRates(const_cast<double*> (payRates), NUM_PAYRATES);

	return 0;
}
}


//how do I create memory for something

new
delete

//before it was like this
nullptr = NULL;
//or
nullptr = 0;
{
int* ptr = nullptr; //known value that can be assigned into that memory location in that ptr; is it's own value

ptr = new int; //allowcates an integer in memory; it takes the value of mem address of where it's stored and brings it back to the pointer

*ptr = 123; //now we place that into where that new int was.

std::cout << *ptr << std::endl;


delete ptr; // removes the new int from memory, the pointer is still around until we leave the function, but removes the int we asked for
ptr = nullptr;
//dangling pointer: have a pointer, free memory up, but didn't reset
//memory leak, make
//we leave the function;
}

{
	#include <iostream>
#include <iomanip>

void displayPayRates(const double* rates, unsigned int size)
{
	std::cout << std::setprecision(2) << std::fixed << std::showpoint;
	for (unsigned int payRate = 0; payRate < size; payRate++)
	{
		std::cout << "pay rate is $" << *(rates + payRate) << std::endl;
	}
}



int main()
{
	int* ptr = nullptr; //blanked out memory value; then nullpointer is a zero

	ptr = new int; //new address

	*ptr = 123; //set value to that address
	std::cout << *ptr << std::endl;

	delete ptr; //deleted the memory that is at this memory address
	*ptr = 124; //you shouldn't do this


	ptr = nullptr;

	return 0;
}
}

{
#include <iostream>
#include <iomanip>

void displayPayRates(const double* rates, unsigned int size)
{
	std::cout << std::setprecision(2) << std::fixed << std::showpoint;
	for (unsigned int payRate = 0; payRate < size; payRate++)
	{
		std::cout << "pay rate is $" << *(rates + payRate) << std::endl;
	}
}

//class that has member function; you don't have to allocate memory for it, it does it by itself
//std::vectors



int main()
{
	int* ptr = nullptr;

	ptr = new int[1000]; //array of 1000 int

	//ptr = new Rectangle(10, 20); //now you have a pointer to that rectangle, whatever the type is, you can allocate it

	for (unsigned int i = 0; i < 1000; i++)
	{
		ptr[i] = i;
	}

	delete[]ptr; //delete the array of int



	return 0;
}
}
