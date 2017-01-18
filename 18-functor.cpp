static_cast<int>(a)

operator int() {
	return m_feet * 12 + m_inches;
}


//Function Objects / functor

class SumFunctor{
public:
	//overloading () operator
	int operator()(int a, b) {
		return a + b;
	}
	
}



SumFunctor functor;
std::cout << functor(1,2) << std::endl; //like using class a function

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Functors = Function Objects


class SumFunctor{
public:
	int operator()(int a, int b){
		return a + b;
	}

private:
};

class IsOdd{
public:
	bool operator()(int x){
		return x % 2 == 1;
	}
};

class LessThan{
public:
	bool operator()(int a, int b){
		return a < b;
	}
};

class GreaterThan{
public:
	bool operator()(int a, int b){
		return a > b;
	}
};

int main(){
	SumFunctor functor;

	//cout << functor.operator()(1, 2) << endl;
	//but because we overloaded
	cout << functor(1, 2) << endl;

	//-------
	vector<int> myData = { 12, 88, 34, 15, 16, 22 };
	auto result = find_if(myData.begin(), myData.end(), IsOdd()); //it infers the return data type, it will go and look at the return type and will become the type
	//IsOdd predicate;
	//auto result = find_if(myData.begin(), myData.end(), predicate);
	cout << *result << endl;

	//--------
	sort(myData.begin(), myData.end(), LessThan()); //sorting the vector with functors

	for (int i = 0; i < myData.size(); i++){
		cout << myData[i] << endl;
	}

	sort(myData.begin(), myData.end(), GreaterThan()); //sorting the vector with functors

	for (int i = 0; i < myData.size(); i++){
		cout << myData[i] << endl;
	}
	//---------


	return 0;
}



//C++11

/*
Lambda Expressions:
*/

//to great to be expressed/ in-f-able

auto SumLambda = [](int a, int b){ //a function that doesn't have a name, assigning it to SumLambda, auto finds the data type and becomes it
	return a+b;
}

cout << SumLambda(1,2) << endl;





#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Functors = Function Objects


class SumFunctor{
public:
	int operator()(int a, int b){
		return a + b;
	}

private:
};

class IsOdd{
public:
	bool operator()(int x){
		return x % 2 == 1;
	}
};

class LessThan{
public:
	bool operator()(int a, int b){
		return a < b;
	}
};

class GreaterThan{
public:
	bool operator()(int a, int b){
		return a > b;
	}
};

int main(){
	SumFunctor functor;

	//cout << functor.operator()(1, 2) << endl;
	//but because we overloaded
	cout << functor(1, 2) << endl;

	//-------
	vector<int> myData = { 12, 88, 34, 15, 16, 22 };
	auto result = find_if(myData.begin(), myData.end(), IsOdd()); //it infers the return data type, it will go and look at the return type and will become the type
	//IsOdd predicate;
	//auto result = find_if(myData.begin(), myData.end(), predicate);
	cout << *result << endl;

	//--------
	sort(myData.begin(), myData.end(), LessThan()); //sorting the vector with functors

	for (int i = 0; i < myData.size(); i++){
		cout << myData[i] << endl;
	}

	sort(myData.begin(), myData.end(), GreaterThan()); //sorting the vector with functors

	for (int i = 0; i < myData.size(); i++){
		cout << myData[i] << endl;
	}
	//---------

	auto lambda = [](int a, int b) {return a + b; };

	cout << lambda(1, 2) << endl;

	sort(myData.begin(), myData.end(), [](int a, int b) {return a > b; }); //sorting with the lambda

	for (int i = 0; i < myData.size(); i++){
		cout << myData[i] << endl;
	}




	return 0;
}











































































