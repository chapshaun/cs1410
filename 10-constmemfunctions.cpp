//What you should turn in

.sln
.vcsproj
.filters
.hpp
.cpp



//Constant Member Functions

#include <iostream>

// Chapter 11

class ConstExample
{
public:
	ConstExample(int a) :
		x(a)
	{}

	void setValue(int x) { this->x = x; }

	int getValue() const // this method is not allowed to change any members of the class
	{
		return x;
	}

private:
	int x;


};


int main()
{

	ConstExample myObj(10);

	std::cout << myObj.getValue() << std::endl;







	return 0;
}

#include <iostream>

// Chapter 11

class ConstExample
{
public:
	ConstExample(int a) :
		x(a)
	{}

	void setValue(int x) { this->x = x; }

	int getValue() const; // this method is not allowed to change any members of the class

private:
	int x;


};

int ConstExample::getValue() const
{
	return x;
}


int main()
{

	ConstExample myObj(10);

	std::cout << myObj.getValue() << std::endl;







	return 0;
}

//static member: it's life time is for the lengh when the program is running, only one of them.

























