#ifndef _SIMPLE_HPP_
#define _SIMPLE_HPP_

template<typename T>
class simple{
public:
	simple(unsigned int size);
	simple(const simple& obj);
	~simple();
	
	unsigned int getSize();
	T& operator[](const int index);
	
	class OutOfBounds {};
	
private:
	T* m_data;
	unsigned int m_size;
};

//constructor
template<typename T>
simple<T>::simple(unsigned int size) :
	m_size(size)
	{
		m_data = new T[size];
	}
	
//copy constructor
template<typename T>
simple<T>::simple(const simple& obj){
	m_size = obj.m_size;
	m_data = new T[m_size];
	for(unsigned int index = 0; index < m_size; index++){
		m_data[index] = obj.m_data[index];
	}
}

//overloaded operator
template<typename T>
T& simple<T>::operator [](const int index){
	if(index < 0 || index >= m_size){
		throw simple<T>::OutOfBounds();
	}
	return m_data[index];
}

//getsize
template<typename T>
unsigned int simple<T>::getSize(){
	return m_size;
}

//destructor
template<typename T>
simple<T>::~simple(){
	if(m_size != 0){
		delete[] m_data;
	}
}

#endif




#include <iostream>
#include <algorithm>
#include <string>
#include "simple.hpp"


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
	
	
	simple<int> myInts(10);
	simple<std::string> myStings(10);
	
	myInts[0] = 1;
	myStings[0] = "Hi mom";
	
	cout << myInts[0] << endl;
	
	cout << myStings[0] << endl;
	
	return 0;
}