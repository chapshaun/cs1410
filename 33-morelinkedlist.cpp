//main
#include <iostream>
#include <string>
#include "LinkedList.hpp"

int main(){
	LinkedList<std::string> myList;
	myList.append("Stephanie");
	
	return 0;
}

//LinkedList.hpp
#ifndef _LINKEDLIST_HPP_
#define _LINKEDLIST_HPP_

template <typename T>
class LinkedList{
public:
	void append(T value);
private:
	struct ListNode{
		
		ListNode(): 
		next(nullptr)
		{
			
		}
		
		ListNode(T data) :
		data(data),
		next(nullptr)
		{
			
		}
		
		T data;
		ListNode* next;
	};
	
	ListNode m_head;
	
};

void LinkedList<T>::display(){
		ListNode* ptrCurrent = m_head.next;
		while(ptrCurrent != nullptr){
		
	}
}

template <typename T>
void LinkedList<T>::append(T value){
	ListNode* ptrNew = new ListNode(value);
	ListNode* ptrEnd = &m_head;
	while(ptrEnd->next != nullptr){
		ptrEnd = ptrEnd->next;
	}
	ptrEnd->next = ptrNew;
}

#endif