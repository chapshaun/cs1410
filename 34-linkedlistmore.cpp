/*
inserting a node 
	create a node
	store the data
	find appropriate node
	insert between nodes

insert(T);

	ptrCur to point to what head node is pointing to
	ptrPrev to point to the head node

	
*/

#include <iostream>
#include <string>
#include "LinkedList.hpp"

int main(){
	LinkedList<std::string> myList;
	myList.insert("Stephanie");
	myList.insert("Scott");
	myList.insert("Alli");
	myList.insert("Dave");
	
	myList.display();
	
	return 0;
}



#ifndef _LINKEDLIST_HPP_
#define _LINKEDLIST_HPP_

template <typename T>
class LinkedList{
public:
	void append(T value);
	void display();
	void insert(T value);
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

template <typename T>
void LinkedList<T>::display(){
		ListNode* ptrCurrent = m_head.next;
		while(ptrCurrent != nullptr){
			
			
		std::cout << ptrCurrent->data << std::endl;
		ptrCurrent = ptrCurrent->next;
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

template <typename T>
void LinkedList<T>::insert(T value){
	ListNode* ptrNew  = new ListNode(value);
	ListNode* ptrCurrent = m_head.next;
	
	ListNode* ptrPrevious = &m_head;
	
	while(ptrCurrent && ptrCurrent->next && ptrCurrent->data < value){
		ptrPrevious = ptrCurrent;
		ptrCurrent = ptrCurrent->next;
	}
	
	ptrPrevious->next = ptrNew;
	ptrNew->next = ptrCurrent;
}

#endif