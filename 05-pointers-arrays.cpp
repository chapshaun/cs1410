{
	//Relationship between pointers and arrays

#include <iostream>

void doubleValue(int* value)
{
	*value = (*value) * 2;

}

void doubleValue2(int& value)
{
	value = value * 2;
}

int main()
{
	int myValue1 = 2;
	int myValue2 = 2;

	doubleValue(&myValue1);
	doubleValue2(myValue2);

	std::cout << myValue1 << " : " << myValue2 << std::endl;


	//int numbers[] = { 10, 20, 30, 40, 50 };
	//int* ptr = numbers;

	//std::cout << *numbers << std::endl;
	//std::cout << *(numbers + 1) << std::endl;

	//std::cout << numbers << std::endl;
	//std::cout << numbers + 1 << std::endl;

	//std::cout << *ptr << std::endl;
	//ptr++;
	//std::cout << *ptr << std::endl;

	//std::cout << ptr[0] << std::endl;
	//std::cout << ptr[1] << std::endl;


	////comparing addresses
	//int array[5];

	//if (&array[1]>&array[0])

	//if (array < &array[4])

	//if (array == &array[0])

	//if (&array[2] != &array[3])

	////comparing values 
	//if (*ptr < *ptr2)

	////
	//int myArray[5];
	//int* ptr = myArray;

	//std::cout << *(ptr + 1) << std::endl;






	return 0;
}
}