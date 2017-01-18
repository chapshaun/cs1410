//Finishing Chapter 10

//Smart pointer
//will allocate deallocate memory, you allowcate it, but you don't have to deallocate the memory
//when the pointer goes out of scope, it will automatically clear the memory

#include <boost>
//introduced smart pointer

	//"raw pointer" the normal pointers
	//smart pointers wraps a raw pointer
	//it's like a class managing the raw pointer

	#include <memory>

	std::unique_ptr // only one variable can contain the raw pointer; only one can refer to the allocated memory

	// how to declare and use

	std::unique_ptr<int> pInt(new int); //data type: std::unique_ptr<int>; declare the variable name:; creating raw pointer, handing it to the class, and the class will handle it
	pInt = std::makeunique<int>(10); // the code behind, creates the unique pointer and the raw pointer all at once; allows more efficiency
	//with the other one, you have two memory allocation

	int* pInt = new int; // the same thing, old style

	*pInt = 10; //dereference and assign the value 10 to it

	//another way

	std::unique_ptr<int> pInt2; // there is no raw pointer that is allocated
	pInt2 = std::makeunique<int>(10); // will create unique pointer, assign the value 10



	////allocate an array of integers

	std::unique_ptr<int[]> pArray(new int[6]);

	//comparison
	std::unique_ptr<int> a(new int);
	std::unique_ptr<int> b;

	*a = 10;
	b = a; // error in, only one pointer can point to the unique pointer, we don't want a copy; we are going to move the value

	b = std::move(a); // 'a' losses the value a;


	//CODE:
#include <iostream>
#include <memory>


int main()
{
	std::unique_ptr<int> pInt(new int(5));

	std::unique_ptr<int> pInt2 = std::make_unique<int>(6);

	std::unique_ptr<int> pDest;


	std::cout << *pInt << " : " << *pInt2 << std::endl;

	*pInt = 7;
	*pInt2 = 8;

	std::cout << *pInt << " : " << *pInt2 << std::endl;

	*pInt = *pInt2; // you can make copies of the values, but not copies of the pointers

	pDest = std::move(pInt2); // take the pInt and move it to pDest now pint2 has nothing, we never allocated a pointer, we just moved one that was already allocated

	std::cout << *pDest << std::endl;
	//std::cout << *pInt2 << std::endl;  //pint2 has nothing, so there will be an error


	return 0;
}


//if your passing by reference, no move is neccessary




//shared pointer

std::shared_ptr<int> a = std::make_shared<int>(6);
std::shared_ptr<int> b = a; // now b gets a copy of the memory address

//if 'a' dissapears, 'b' remains the value; but if 'b' goes out of scope, so when the last one goes out, the memory is cleaned out

//you can't do this
std::shared_ptr<int[]> b = a; // it wont clean up very well when using array; shared pointer won't clean it up.




//Assignment 3:

//first number tells you how many to read

std::vector<IPRecord*> v; //making a vector of pointers

v.insert(v.begin()+0, IPRecord);

	// read 46, do binary search to see if it's in there

	//| 46 |

	//read 32, do binary search to see if it's in there

	// 32 | 46 |

	//reads 46, do binary search to see if it's in there

	// increment frequency since it did find it.



	//all these numbers, then they will have frequencies in there
	//now we sort it by frequency
