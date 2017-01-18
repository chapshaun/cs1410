/*
Binary Search with Recursion


*/
#include <iostream>

using namespace std;

//binary search with recursion
bool binarySearch(int data[], int first, int last, int value){
	if (first > last) return false;

	int middle = (first + last) / 2;
	if (data[middle] == value){
		return true;
	}
	if (data[middle] < value){
		return binarySearch(data, middle + 1, last, value);
	}
	
	return binarySearch(data, first, middle - 1, value);
}


int main(){
	int data[] = { 0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
	cout << binarySearch(data, 0, 10, 3) << endl;

	cout << binarySearch(data, 0, 10, 4) << endl;


	return 0;
}





/*
Quick sort:

|             |
choose some value called a pivot value (choose the middle item)

smaller(22)bigger
s     b     s     b
s b   s b   s b   s back


Partioning Algorighm

	1) compute the middle
		swap value[start], value[middle]
	2) current pivot value = middle
	3) initial pivot index = first pos
	4) scan rest of partition
		if value[scan] < pivot value
			update pivot index
			swap value[scan], value[pivot index]
	5) swap value[first], value[pivot index]

*/




























