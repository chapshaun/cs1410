/*
deleting from a tree

	delete a node that has not children
		two pointers, set the pointer to nothing and delete the thing

	with one child
		

	with two children


*/

/*
counting nodes

*/

int countNodes(TreeNode* node){
	if(node == nullptr) return 0;

	return it
}

int countLeafNodes(TreeNode* node){
	//if both left and right are null
		return 1;

	return count of left + count of right

}

int height(TreeNode* node){
	compute the left subtree height 
	compute the right subtree height
	height = max(left, right) + 1;
}



//binary search tree
#include <iostream>
#include <string>
#include "BinarySearchTree.hpp"
using namespace std;

int main(){
	BinarySearchTree myTree;
	
	myTree.insert("What");
	myTree.insert("The");
	myTree.insert("Fuck");
	
	
	myTree.display();
	
	myTree.remove("What");
	myTree.remove("The");
	
	cout << "---After Delete---" << endl;
	
	myTree.display();
	
	return 0;
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
	
	void remove(std::string value, TreeNode*& node);

	void remove(TreeNode*& node);
};

#endif




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

void BinarySearchTree::remove(std::string value){
	
	remove(value, m_root);
}

void BinarySearchTree::remove(std::string value, TreeNode*& node){
	
	if(value < node->data){
		
		remove(value, node->left);
		
	}else if(value > node->data){
		
		remove(value, node->right);
		
	}else{
		
		remove(node);
		
	}
}

void BinarySearchTree::remove(TreeNode*& node){
	
	if(node->left == nullptr){
		TreeNode* temp = node;
		node = node->right;
		delete temp;
	}
	else if(node->right == nullptr){
		TreeNode* temp = node;
		node = node->left;
		delete temp;
	}
	else{
		TreeNode* left = node->right;
		while(left->left != nullptr){
			left = left->left;
		}
		left->left = node->left;
		
		TreeNode* temp = node;
		
		node = node->right;
		
		delete temp;
	}
	
}

