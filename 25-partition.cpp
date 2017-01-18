/*
partition
	compute middle -> this is the pivot value_comp
	swap start with middle
	set initial pivot index to start
	scan remainder of sublist
		if value < pivot value
		inc pivot index
		swap value with pivot index
	swap first with pivot index
*/

#include <iostream>
#include <vector>
#include <algorithm>
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

int partition(vector<int>& data, int start, int end){
	int middle = (start + end) / 2;
	int pivotValue = data[middle];
	swap(data[start], data[middle]);
	int pivotIndex = start;
	for (int scan = start + 1; scan <= end; scan++){
		if (data[scan] < pivotValue){
			pivotIndex++;
			swap(data[pivotIndex], data[scan]);
		}
	}
	swap(data[start], data[pivotIndex]);

	return pivotIndex;
}

void quickSort(vector<int>& data, int start, int end){
	if (start < end){
		int pivotIndex = partition(data, start, end);
		quickSort(data, start, pivotIndex - 1);
		quickSort(data, pivotIndex + 1, end);
	}
}


int main(){
	int data[] = { 0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	cout << binarySearch(data, 0, 10, 3) << endl;

	cout << binarySearch(data, 0, 10, 4) << endl;

	vector<int> sortMe = { 10, 0, 9, 1, 8, 2, 7, 3, 6, 4, 5 };
	quickSort(sortMe, 0, sortMe.size() - 1);


	return 0;
}



/*
recursive towers of hanoi

if(m>0)
	move n - 1 discs from peg 1 to peg 2 using peg 3 as temporary
	mova a disc from peg 1 to peg 3
	move n - 1 discs from peg 2 to peg 3 using peg 1 as temporary
	
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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

int partition(vector<int>& data, int start, int end){
	int middle = (start + end) / 2;
	int pivotValue = data[middle];
	swap(data[start], data[middle]);
	int pivotIndex = start;
	for (int scan = start + 1; scan <= end; scan++){
		if (data[scan] < pivotValue){
			pivotIndex++;
			swap(data[pivotIndex], data[scan]);
		}
	}
	swap(data[start], data[pivotIndex]);

	return pivotIndex;
}

void quickSort(vector<int>& data, int start, int end){
	if (start < end){
		int pivotIndex = partition(data, start, end);
		quickSort(data, start, pivotIndex - 1);
		quickSort(data, pivotIndex + 1, end);
	}
}


void moveDisks(unsigned int n, string source, string dest, string temp){
	static unsigned int step = 0;
	if (n > 0){
		moveDisks(n - 1, source, temp, dest);
		step++;
		cout << "Step " << step << " Move a disk from " << source << " to " << dest << endl;
		moveDisks(n - 1, temp, dest, source);
	}
}




int main(){
	//int data[] = { 0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	//cout << binarySearch(data, 0, 10, 3) << endl;

	//cout << binarySearch(data, 0, 10, 4) << endl;

	//vector<int> sortMe = { 10, 0, 9, 1, 8, 2, 7, 3, 6, 4, 5 };
	//quickSort(sortMe, 0, sortMe.size() - 1);


	moveDisks(6, "Peg 1", "Peg 3", "Peg 2");


	return 0;
}

































