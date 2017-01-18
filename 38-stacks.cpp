/*
stacks:
	static
		at the time of creation
		you state size, and if full can't do anything; set when created
		array pointer
	dynamic
		unbounded size
		implemented as a linked list

operations
	push(v)
	v pop()


*/

// templates
// linkedlist
// binarytrees
// stackand queue





#include <iostream>
#include "Stack.hpp"

using namespace std;


int main(){
	
	Stack<int> myStack(10);
	
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	
	cout << myStack.pop() << endl;
	cout << myStack.pop() << endl;
	cout << myStack.pop() << endl;


	
	
	return 0;
}





#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <exception>

template<typename T>
class Stack{
public:
	Stack(unsigned int size);
	
	void push(T value);
	T pop();
	
	bool isFull();
	bool isEmpty();
	
	~Stack();
		
	
private:
	T* m_data;
	unsigned int m_size;
	int m_top;
};

template<typename T>
Stack<T>::Stack(unsigned int size) :
		m_size(size),
		m_top(-1)
	{
		if(size == 0){
			throw std::exception();
		}
		m_data = new T[size];
	}
	
template<typename T>
void Stack<T>::push(T value){
	if(isFull()){
		throw std::exception();
	}
	m_top++;
	m_data[m_top] = value;
}

template<typename T>
T Stack<T>::pop(){
	if(isEmpty()){
		throw std::exception();
	}

	return m_data[m_top--];
}

template<typename T>
bool Stack<T>::isFull(){
	return (m_size == (m_top + 1));
}

template<typename T>
bool Stack<T>::isEmpty(){
	return (m_top == -1);
}

template<typename T>
Stack<T>::~Stack(){
	delete[] m_data;
	
}


#endif





