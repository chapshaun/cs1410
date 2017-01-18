/*
Templates
same functions but different data types

you don't want duplicate code
DRY : don't repeat yourself


*/

int square(int n) {return n*n;}
float square(float n){return n*n;}


square(4);

square(4.2); 




//template function: pattern for a function
template <typename T>
T square(T n){
	return n * n;
}




#include <iostream>
#include <algorithm>


using namespace std;

template <typename T>
T square(T n){
	return n * n;
}

template <typename T, typename T2>
void swap(T& x, T2& y){
	T temp = x;
	x = y;
	y = temp;
}


int main(){
	
	auto result1 = square(10);
	auto result2 = square(10.2);
	


	int a = 10;
	int b = 20;
	float c = 30;
	float d = 40;
	
	cout << a << " " << b << endl;
	cout << c << " " << d << endl;
	
	swap(a,b);
	swap(c,d);
	
	cout << a << " " << b << endl;
	cout << c << " " << d << endl;
	cout << a << " " << d << endl;
	
	return 0;
}




/*
class templates


*/

template <typename T>
class SimpleVector{
public:
	SimpleVector(unsigned int size);
	SimpleVector(const SimpleVector& obj); //copy constructor
	~SimpleVector();
	unsigned int getSize();
	T& operator[](const int index);
private:
	T*  m_data;
	unsigned int m_size;
};



template<typename T>
SimpleVector<T>::SimpleVector(unsigned int size)

//recursion
//that known fact of how to get out, base case(to get out), and recursive step



























































	rn n*n;
}