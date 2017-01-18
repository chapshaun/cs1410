#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>



std::string collapseSpaces(std::string s);
std::vector<std::string> split(std::string s);
bool isPalindrome(std::string word, int start, int end);
bool isWordSymmetric(const std::vector<std::string>& words, int start, int end);
long vectorSum(const std::vector<int>& data, unsigned int position);
int vectorMin(const std::vector<int>& data, unsigned int position);
void quickSort(std::vector<int>& data, int start, int end);
void selectionSort(std::vector<int>& data, int start, int end);
void testPalindromes();
void testWordSymmetry();
void testVectorSum();
void testVectorMin();
void testSort();

int main()
{
	testPalindromes();
	testWordSymmetry();
	testVectorSum();
	testVectorMin();
	testSort();
}

// ------------------------------------------------------------------
//
// Provided pallindome testing code
//
// ------------------------------------------------------------------
void testPalindromes()
{
	std::vector<std::string> possiblePallindromes =
	{
		"radar",
		"racecar",
		"Pull up if I pull up",
		"No lemon no melon",
		"A dog a panic in a pagoda",
		"CS 1410 is my favorite class",
		"Rats live on no evil star",
		"My code compiles without bugs",
		"Never odd or even",
		"Now I see bees I won"
	};

	for (auto test : possiblePallindromes)
	{
		std::string collapsed = collapseSpaces(test);	// Collapse any spaces first
		std::cout << "'" << test << "' is ";
		if (!isPalindrome(collapsed, 0, static_cast<int>(collapsed.length() - 1)))
		{
			std::cout << " NOT ";
		}
		std::cout << "a palindrome." << std::endl;
	}
}

// ------------------------------------------------------------------
//
// Provided word symmetry testing code
//
// ------------------------------------------------------------------
void testWordSymmetry()
{
	std::vector<std::string> possibleSymmetric =
	{
		"You can cage a swallow can't you but you can't swallow a cage can you",
		"Fall leaves as soon as leaves fall",
		"So patient a nurse to nurse a patient so",
		"I still say cS 1410 is my favorite class"
	};

	for (auto test : possibleSymmetric)
	{
		std::transform(test.begin(), test.end(), test.begin(), toupper);	// Capitalize all
		auto words = split(test);	// Split into words
		std::cout << "'" << test << "' is ";
		if (!isWordSymmetric(words, 0, static_cast<int>(words.size() - 1)))
		{
			std::cout << " NOT ";
		}
		std::cout << "word symmetric." << std::endl;
	}
}

// ------------------------------------------------------------------
//
// Provided test vector sum code
//
// ------------------------------------------------------------------
void testVectorSum()
{
	std::vector<int> data = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	std::cout << "The total sum is: " << vectorSum(data, 0) << std::endl;

}

// ------------------------------------------------------------------
//
// Provided test vector min code
//
// ------------------------------------------------------------------
void testVectorMin()
{
	std::vector<int> data = { 0, 1, 1, 2, 3, 5, 8, -42, 13, 21, 34, 55, 89 };
	std::cout << "The minimum value is: " << vectorMin(data, 0) << std::endl;
}

// ------------------------------------------------------------------
//
// Provided test quicksorting code
//
// ------------------------------------------------------------------
void testSort()
{
	std::srand(std::time(NULL));
	std::vector<int> data1(100000);
	std::vector<int> data2(100000);

	for (auto&& item : data1)
	{
		item = std::rand();
	}
	for (auto&& item : data2)
	{
		item = std::rand();
	}

	auto start = std::chrono::high_resolution_clock::now();
	quickSort(data1, 0, data1.size() - 1);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> timeSort = end - start;
	std::cout << "Quicksort sort time    : " << timeSort.count() << " seconds" << std::endl;

	start = std::chrono::high_resolution_clock::now();
	std::sort(data2.begin(), data2.end());
	end = std::chrono::high_resolution_clock::now();
	timeSort = end - start;
	std::cout << "std::sort sort time    : " << timeSort.count() << " seconds" << std::endl;
}

// ------------------------------------------------------------------
//
// Provided code to remove spaces from a string (and capitalize it)
//
// ------------------------------------------------------------------
std::string collapseSpaces(std::string s)
{
	s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());
	std::transform(s.begin(), s.end(), s.begin(), toupper);	// Capitalize all
	return s;
}

// ------------------------------------------------------------------
//
// Provided quicksort partition code
//
// ------------------------------------------------------------------
int partition(std::vector<int>& data, int start, int end)
{
	int middle = (start + end) / 2;
	std::swap(data[start], data[middle]);
	int pivotIndex = start;
	int pivotValue = data[start];
	for (int scan = start + 1; scan <= end; scan++)
	{
		if (data[scan] < pivotValue)
		{
			pivotIndex++;
			std::swap(data[scan], data[pivotIndex]);
		}
	}

	std::swap(data[pivotIndex], data[start]);

	return pivotIndex;
}

// ------------------------------------------------------------------
//
// Provided quicksort code
//
// ------------------------------------------------------------------
/*
Modify the quicksort algorithm to switch to a selection sort when the number of elements to be sorted is less than or equal to 10.
The driver code already includes the quicksort (that we coded during class), you need to provide the selection sort and correctly use it in the quicksort.
The driver code also provides a timing comparison of our quick/selection sort hybrid compared to the built-in std::sort algorithm.
In Visual Studio compile for "Release" to see an accurate timing comparison.  For Linux users, add a "-O3" compiler option, this will enable
optimization to see an accurate timing comparison
*/
void quickSort(std::vector<int>& data, int start, int end)
{
	if ((end - start) > 10) { // if the number of elements that need to be sorted is greater than 10
		//quick sort implementation given
		if (start < end)
		{
			int pivot = partition(data, start, end);
			quickSort(data, start, pivot - 1);
			quickSort(data, pivot + 1, end);
		}
	}
	else if ((end - start) <= 10) { //if the number of elements that need to be sorted is equal or less than 10
		selectionSort(data, start, end);
	}
}

void selectionSort(std::vector<int>& data, int start, int end){
	//selection sort implementation
	for (int i = start; i < (end - 1); i++) {
		int min = i;
		for (int scan = i + 1; scan < end; scan++) {
			if (data[scan] < data[min]) {
				min = scan;
			}
		}
		std::swap(data[i], data[min]);
	}
}

//-------------------------------------------------------------------
//							 MY CODE
//-------------------------------------------------------------------

/*-----------------------------------------------------------------------------------------------
Description: A word or phrase is a palindrome if it is spelled the same forwards or backwards.
For example, "radar" is a palindrome.
Also, "No lemon no melon" is a palindrome; if you remove spaces.
You are provided test code that takes care of remove spaces from a string, you have to write
the 'isPalindrome' function that performs the test.
-----------------------------------------------------------------------------------------------*/
//isPalindrome Function: test a string to determine if it is a palindrome
bool isPalindrome(std::string word, int start, int end) {
//	bool isPal = false; //creating a bool that the function will return
//	if(word[start] == word[end]){ //if starting letter is the same as ending letter
//		isPal = true; //base case
//	}
//	if(isPal == false){ 
//		return isPal;
//	}
//	start++; //increment the starting word
//	end--; //decrement the ending word
//	return isPal;

	if((end - start) < 2){
		return true; //base case
	}
	else if(word[start] == word[end]){
		return isPalindrome(word, ++start, --end); //increment start, decrement end
	}
	return false;
}

/*-------------------------------------------------------------------------------------------
Description: Similar to a palindrome, a phrase is symmetric if the words
placed forward or backwards say the same thing.
For example, "Fall leaves as soon as leaves fall" is word symmetric.
You are provided test code that takes care of capitalizaton,
you need to write a 'split' function
(using what you have learned from stringstreams) to break the phrase into individual words,
and then write the 'isWordSymmetric' function.
--------------------------------------------------------------------------------------------*/

//split Function
std::vector<std::string> split(std::string s) {

	std::vector<std::string> words; //creating a vector for words 
	std::string stream;
	std::istringstream is(s); //inputing the s string
	std::ostringstream os;

	while(!is.eof()){ //when the input string is not at the end
		std::string word; //create a string for each word
		is >> word; //input that stream into that word
		words.push_back(word); //insert that word into the vector words
	}
	return words; //return the vector words

}

//isWordSymmetric Function: test a string to determine if it is word symmetric
bool isWordSymmetric(const std::vector<std::string>& words, int start, int end) {
//	bool isSym = false;
//	if(words[start] ==words[end]){
//		isSym = true;
//	}
//	if(isSym == false){
//		return isSym;
//	}
//	start++;
//	end--;
//	return isSym;

	if((end - start) < 2){
		return true; //base case
	}
	else if(words[start] == words[end]){
		return isWordSymmetric(words, ++start, --end); //increment start, decrement end
	}
	return false;

}


/*--------------------------------------------------------------------------------------------
Description: Write a recursive function that returns the total of all elements in the vector.
You may assume there is at least one value in the vector.
---------------------------------------------------------------------------------------------*/
//vectorSum Function: return the sum of all elements in a vector
long vectorSum(const std::vector<int>& data, unsigned int position) {
	if (position == data.size()){
		return 0; //base case
	}
	else{
		return data[position] + vectorSum(data, position + 1); //return that position plus the next position
	}
}


/*----------------------------------------------------------------------------------------------------
Description: Write a recursive function that returns the minimum value of the elements in the vector.
You may assume there is at least one value in the vector.
------------------------------------------------------------------------------------------------------*/
//vectorMin Function: return the minimum value in an unordered vector
int vectorMin(const std::vector<int>& data, unsigned int position) {
	if(position == data.size() - 1){
		return data[0]; //base case
	}
	position++; //increment position
	if(data[position] < vectorMin(data, position)){
		return data[position]; //return that position
	}else{
		return vectorMin(data, position); //return the next position
	}
}



