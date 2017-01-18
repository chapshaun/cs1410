class ListNode{
public:
	ListNode(int data) :
	data(data),
	next(nullptr)
	{}

	int data;
	ListNode* next;
};

class LinkedList{
public:
	LinkedList():m_head(0){}

	void display();
	void append(int value);
	void insert(int value);

private:
	ListNode m_head;
};

//----------------------------
/*
Append A node
	create a new node
	store the data in the node
	treverse to the end
	update pointers
*/


