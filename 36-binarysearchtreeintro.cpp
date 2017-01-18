//binary tree: a nonlinear data structure, not like a linked list
/*
each node has two pointers left and right

tree pointer

root node: only node that doesn't have a node before it, also a parent node

other nodes: child nodes

leaf node: is a node that doesn't have any children



*/


/*
binary search tree: it is a binary tree, but not the other way around


every node has a specific property

all nodes to left are smaller and all nodes to the right are larger


just like a binary search
but it's easier to insert some things


*/


/*
traversals
	in-order:
		follow left
		process data
		follow right

	pre-order:
		process node
		follow left
		follow right

	post-order
		follow left
		follow right
		process data

*/



//binary search tree
#include <iostream>
#include <string>
#include "BinarySearchTree.hpp"
using namespace std;

int main(){
	BinarySearchTree myTree;
	
	myTree.insert("5");
	myTree.insert("8");
	myTree.insert("3");
	myTree.insert("1");
	myTree.insert("2");
	myTree.insert("9");
	
	myTree.display();
	
	return 0;
}


#include "BinarySearchTree.hpp"
#include <iostream>
#include <string>


void BinarySearchTree::insert(std::string value){
	
	TreeNode* newNode = new TreeNode(value);
	
	insert(m_root, newNode);
}

void BinarySearchTree::insert(TreeNode*& node, TreeNode* newNode){
	
	if(node == nullptr){
		node = newNode;
	}
	else if(newNode->data < node->data){
		insert(node->left, newNode);
	}
	else{
		insert(node->right, newNode);
	}
	
}

void BinarySearchTree::display(){
	display(m_root);
}

void BinarySearchTree::display(TreeNode* node){
	
	if(node != nullptr){
		display(node->left);
		std::cout << node->data << std::endl;
		display(node->right);
	}
	
}



#ifndef _BINARYSEARCHTREE_HPP_
#define _BINARYSEARCHTREE_HPP_
#include <string>

class BinarySearchTree{
public:
	BinarySearchTree() : 
		m_root(nullptr)
	{}
	
	void insert(std::string value);
	void remove(std::string value);
	void search(std::string value);
	void display();
	
	// ... various display ...
	
private:
	class TreeNode{
	public:
		
		TreeNode(std::string data) : 
			data(data),
			left(nullptr),
			right(nullptr)
		{}
		
		std::string data;
		TreeNode* left;
		TreeNode* right;
	};
	
	TreeNode* m_root;
	
	void insert(TreeNode*& node, TreeNode* newNode);
	
	void display(TreeNode* node);
};

#endif



/*
assignment:

read dictionary into vector

generate random number
pick it
insert into tree
remove from vector
*/