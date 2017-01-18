/*
Linked List:
	dynamically allocated list of linked structures

	define a node:
		data section
		pointer, to another node

			data section
			pointer, to another node

				last node:
					data section
						pointer to nullptr;

*/

//decloration for one of these nodes:

class ListNode{
public:
	ListNode(): next(nullptr) {

	}

	float data;
	ListNode* next;
}


/*
Different operations you can do on a linked list

	apppend
	insert
	delete
	display(treversal) you start at beginning and you go down it
*/