/*Bubble Sort:
Things bubble to the top; this is also n^2
*/

//Bubble Sort: n^2, it's work intensive

void sortBubble(int data[], unsigned int size)
{
	bool didSwap = false;

	do
	{
		didSwap = false;
		for (unsigned int item = 0; item < (size - 1); item++)
		{
			if (data[item] > data[item + 1])
			{
				//int temp = data[item];
				//data[item] = data[item + 1];
				//data[item + 1] = temp;

				std::swap(data[item], data[item + 1]);
				didSwap = true;
			}
		}
	} while (didSwap);

}

void printData(int data[], unsigned int size)
{
	std::cout << "---Array Contents---" << std::endl;
	for (unsigned int item = 0; item < size; item++)
	{
		std::cout << data[item] << std::endl;
	}
	std::cout << std::endl;
}
	
int main()
{
	int data[] = { 7, 2, 8, 3, 9, 6, 5, 1 };

	sortBubble(data, 8);

	printData(data, 8);


	return 0;
}
}

/*Selection Sort:
Selection Sort: n^2; (it only swaps once) more efficient than bubble sort
	start
	min
	scan
*/


void sortSelection(int data[], unsigned int size)
{
	for (unsigned int start = 0; start < (size - 1); start++)
	{
		unsigned int minPos = start;

		for (unsigned int scan = start + 1; scan < size; scan++)
		{
			if (data[scan] < data[minPos])
			{
				minPos = scan;
			}
		}
		std::swap(data[start], data[minPos]);
	}
}

void printData(int data[], unsigned int size)
{
	std::cout << "---Array Contents---" << std::endl;
	for (unsigned int item = 0; item < size; item++)
	{
		std::cout << data[item] << std::endl;
	}
	std::cout << std::endl;
}
	
int main()
{
	int data[] = { 7, 2, 8, 3, 9, 6, 5, 1 };

	//sortBubble(data, 8);
	sortSelection(data, 8);



	printData(data, 8);


	return 0;
}
}

