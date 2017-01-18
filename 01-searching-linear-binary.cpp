//Chapter 9: Searching
//Linear Search, Binary Search

/*Linear Search, doesn't matter the order of the data, you just go through the list, you find the first first one.
The linear search is a very simple algorithm. Sometimes called a sequential search, it uses a loop to sequentially step through an array, starting with the first element. 
It compares each element with the value being searched for, and stops when either the value is found or the end of the array is encountered. If the value being searched for is not 
the array, the algorithm will search to the end of the array.
*/

//Pseudo Code: Linear Search
// set found to false
// set position to 0
	// while (found is false and position is less than size)
		// if list (position) equal to search
			// set found to true
		// else
			// increment the position
	// end while
	// return found (boolean true or false)
// }

//LINEAR SEARCH

//Chapter 9: Searching; Linear Search and Binary Search

bool searchLinear(int key, int list[], unsigned int size, unsigned int& position)
{
	bool found = false;

	position = 0;

	while (!found && position < size)
	{
		if (list[position] == key)
		{
			found = true;
		}
		else
		{
			position++;
		}
	}

	return found;
}

int main()
{
	int list[] = { 10, 1, 9, 2, 8, 3, 7, 4, 6, 4};
	unsigned int position;
	bool found = searchLinear(4, list, 10, position);

	if (found)
	{
		std::cout << "We found the value at postion: " << position << std::endl;
	}
	else
	{
		std::cout << "Did not find the search value" << std::endl;
	}

	return 0;
}










//Binary Search, must be sorted, lowest to highest or highest to lowest
//everytime we make a choice, we're eliminating half the items

//lower bound and upper bound
//lower + upper / 2; find the middle

//Pseudo Code: Binary Search
//set lower to 0
//set upper to size-1
//set found to false
//while(found is false and lower is less than or equal to upper)
//	set middle to (lower + upper / 2)
//	if list (middle) equal to key
//		set found to true
//		set position to middle
//	else if list (middle) > key
//		set upper to middle -1
//	else 
//		set lower to middle +
//	end if
//end while
//return found




//BINARY SEARCH

bool searchBinary(int key, int list[], unsigned int size, unsigned int& position)
{
	bool found = false;
	int lower = 0;
	int upper = size -1;

	while (!found && lower <= upper)
	{
		int middle = (lower + upper) / 2;
		if (list[middle] == key)
		{
			found = true;
			position = middle;
		}
		else if (list[middle] > key)
		{
			upper = middle - 1;
		}
		else
		{
			lower = middle + 1;
		}
	}

	return found;
}

int main()
{
	int list[] = { 10, 1, 9, 2, 8, 3, 7, 4, 6, 4};
	int list2[] = { 0, 1, 2, 3, 5, 7, 11, 13, 17, 23 };

	unsigned position;
	bool found = searchBinary(7, list2, 10, position);

	if (found)
	{
		std::cout << "We found the value at postion: " << position << std::endl;
	}
	else
	{
		std::cout << "Did not find the search value" << std::endl;
	}

	return 0;
}




//Compare:
//linear search: 1 mill items // doesn't have to be sorted
	//n/2 = 500k
	
//binary search: 1 mill items // has to be sorted
	//20