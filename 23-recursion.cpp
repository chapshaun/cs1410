//Recursion:
/*
Recursive function: a function that calls itself


*/

void message(){
	cout << "Hi Mom" << endl;
	message();
}

//--------

class RecursionDemo{
public:
	RecursionDemo() { m_count=0; }
	
	void message(){
		if(m_count == 4) return;
		cout << "Hi Mom" << endl;
		m_count++
		message();
	}



private:
	int m_count;
	
};

//------
message(0);

void message(int count){
	if(count == 4) return;
	cout << "Hi Mom" << endl;
	message(count++);
}

//------

/*
call stack

count: 0
count++: 1
count: 2
count: 3
count: 4

count: 0
count++: 1
count: 2
count: 3

count: 0
count++: 1
count: 2


we see one, but we are actually making copies(5 copies), you should pass by reference here


*/

//----------

/*
stack frame:

char e
string aeei
index 0

return 0 + 
----------

char e
string aeei
index 1

return 1 + 
----------

char e
string aeei
index 2

return 1 +
----------

char e
string aeei
index 3

return 0 +
----------

char e
string aeei
index 4
----------
return 0

they will now begin to pop off, and count all the return



*/


#include <iostream>
#include <string>
//for loop is faster than recursion

using namespace std;

void message(int times){
	if (times <= 0) return;
	cout << "Hi mom" << endl;
	message(times - 1); //-- use the value then change it, use -- before or - 1
}

int numTimes(char search, const string& message, int index){
	if (index == message.length()) return 0;

	if (message[index] == search){
		return 1 + numTimes(search, message, index + 1);
	}

	return 0 + numTimes(search, message, index + 1);


}

unsigned long factorial(unsigned n){
	if (n == 0) return 1;
	
	return n * factorial(n - 1);
}

long fib(unsigned n){
	if (n == 0) return 0;

	if (n == 1) return 1;

	return fib(n - 1) + fib(n - 2);
}




int main(){

	//message(6);

	//-----

	//cout << numTimes('i', "This is a test of the numTimes function", 0) << endl;

	//-----

	cout << "The factorial of 10 is: " << factorial(10) << endl;

	//-----

	cout << "The fibonacci of 24 is: " << fib(24) << endl;



	return 0;
}




















