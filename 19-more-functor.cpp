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

class PrintDivisibleBy{
public:

	PrintDivisibleBy(int n) :
		m_n(n)
	{}
	void operator()(int x){
		if (x % m_n == 0){
			cout << x << " is divisible by " << m_n << endl;
		}
	}
private:
	int m_n;
};

class TotalValue{
public:
	TotalValue() :
		m_total(0)
	{

	}

	void reset(){};

	int operator()(int v){
		m_total += v;
		return m_total;
	}
private:
	int m_total;
};

int main(){
	SumFunctor functor;

	//cout << functor.operator()(1, 2) << endl;
	//but because we overloaded
	cout << functor(1, 2) << endl;

	//--------
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

	//------

	PrintDivisibleBy byTwo(2);

	for_each(myData.begin(), myData.end(), byTwo);

	for_each(myData.begin(), myData.end(), PrintDivisibleBy(6));


	//--------

	TotalValue total;
	for (auto v : myData){
		cout << "running total is " << total(v) << endl;
	}

	total.reset();

	//--------


	return 0;
}









//Aggregation and Composition: class composed within another class. composition is a specific usage
//the lifetime of the objects that are arrgegated, it's the same of the lifetime of the class that it's in

//Always aggregation but when there's pointers it's only aggregation.

class Person{

private:

public:
	Date m_birthdat;

}

//------------
#include <iostream>
#include <string>
#include <memory>


using namespace std;

class Date{
public:
	Date(string month, int day, int year) :
		m_month(month),
		m_day(day),
		m_year(year)
	{}

private:
	string m_month;
	int m_day;
	int m_year;
};

class Person{
public:
	Person(string name, string month, int day, int year) :
		m_name(name),
		m_birth(month, day, year)
	{}
private:
	string m_name;
	Date m_birth;
};

int main(){
	Person employee1("Jane", "October", 13, 1998);
	Person* employee2("John", "September", 14, 1998);
	shared_ptr<Person> employee3 = make_shared<Person>("Alli", "September", 28, 1995);

	delete employee2;

	return 0;
}





//--------------------

/*
"is a" relationship

Insect
	Ant 'is a' insect
	Bee 'is a' insect
	Housefly 'is a' housefly
	Grasshopper 'is a' insect

*/
class Insect{
public:

private:
	string color;
};

class Bee : public Insect{
public:


private:
	double wingSize;
};

class Ant : public Insect{
public:

private:
	double strenghtToWeight;
};
