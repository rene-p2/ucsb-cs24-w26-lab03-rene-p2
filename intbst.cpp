// intbst.cpp
// Implements class IntBST
// Rene Paredes 1/27/2026

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() { 
	root = nullptr;
}

// destructor deletes all nodes
IntBST::~IntBST() {
	if (root == nullptr){
		return;
	}
	clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
	if (n == nullptr){
		return;
	}
	clear(n->left);
	clear(n->right);
	delete n;
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
	if (root == nullptr){
		root = new Node;
		root->right = nullptr;
		root->left = nullptr;
		root->parent = nullptr;
		root->info = value;
		return true;
	}
	if (insert(value, root)){
		return true;
	}
	else{
	    	return false;
	}
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) 
{
	if (value == n->info){
		return false;
	}
	else if (value > n->info){
		if (n->right == nullptr){
			Node *p = new Node;
			p->right = nullptr;
			p->left = nullptr;
			p->parent = n;
			p->info = value;
			n->right = p;
			return true;
		}
		else{
			return insert(value, n->right);
		}
	}
	else{
		if (n->left == nullptr){
			Node *p = new Node;
			p->right = nullptr;
			p->left = nullptr;
			p->parent = n;
			p->info = value;
			n->left = p;
			return true;
		}
		else{
			return insert(value, n->left);
		}
	}
	return false;
}

// print tree data pre-order
void IntBST::printPreOrder() const {
	if (root == nullptr){
		return;
	}
//	if (root->left == nullptr && root->right == nullptr){
//		cout << root->info << endl;
//		return;
//	}
	printPreOrder(root);
//	cout << endl;
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
	if (n == nullptr){
		return;
	}
	cout << n->info << " ";
	printPreOrder(n->left);
	printPreOrder(n->right);
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
	if (root == nullptr){
		return;
	}
	if (root->left == nullptr && root->right == nullptr){
		cout << root->info << endl;
		return;
	}
	printInOrder(root);
//	cout << endl;
}
void IntBST::printInOrder(Node *n) const {
	if (n == nullptr){
		return;
	}
	printInOrder(n->left);
	cout << n->info << " ";
	printInOrder(n->right);
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    if (root == nullptr){
	    return;
	}
    if (root->left == nullptr && root->right == nullptr){
	    cout << root->info << endl;
	    return;
	}
    printPostOrder(root);
//    cout << endl;
}

void IntBST::printPostOrder(Node *n) const {
	if (n == nullptr){
		return;
	}
	printPostOrder(n->left);
	printPostOrder(n->right);
	cout << n->info << " ";
}

// return sum of values in tree
int IntBST::sum() const {
	if (root == nullptr){
		return 0;
	}
	else if (!root->right && !root->left){
		return root->info;
	}
	else{
		return sum(root);
	}
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
	if (n == nullptr){
		return 0;
	}
	return sum(n->left) + n->info + sum(n->right);

}

// return count of values
int IntBST::count() const {
	if (root == nullptr){
		return 0;
	}
	return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
	if (n == nullptr){
		return 0;
	}
	return count(n->left) + 1 + count(n->right);

}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
	if (!n){
		return nullptr;
	}
	if (n->info == value){
		return n;
	}
	else if (n->info > value){
		return getNodeFor(value, n->left);
	}
	else{
		return getNodeFor(value, n->right);
	}
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
	if (getNodeFor(value, root) != nullptr){
		return true;
	}
	else{
		return false;
	}
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
	Node *hi = getNodeFor(value, root);
	if (hi == nullptr){
		delete hi;
		return nullptr;
	}
	if (hi->left != nullptr){
		hi = hi->left;
		while (hi->right){
			hi = hi->right;
		}
		return hi;
	}
	if (hi->parent != nullptr && hi->parent->info < hi->info){
		return hi->parent;
	}
	else{
		return nullptr;
	}
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
	Node *pred = getPredecessorNode(value);
	if (pred == nullptr){
		return 0;
	}
	else{
		return pred->info;
	}
}
// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
	Node *hi = getNodeFor(value, root);
	if (hi == nullptr){
		return nullptr;
	}
	if (hi->right != nullptr){
		hi = hi->right;
		while (hi->left){
			hi = hi->left;
		}
		return hi;
	}
	if (hi->parent != nullptr && hi->parent->info > hi->info){
		return hi->parent;
	}
	else{
		return nullptr;
	}
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
	Node *succ = getSuccessorNode(value);
		if (succ == nullptr){
			return 0;
		}
		else{
			return succ->info;
		}
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
	Node *hi = getNodeFor(value, root);
	if (!hi){
	//	delete hi;
		return false;
	}
	if (hi->parent == nullptr && hi->right == nullptr && hi->left == nullptr){
		delete hi;
		return true;
	}
	if (hi->parent == nullptr && hi->left && hi->right == nullptr){
		hi->left->parent = nullptr;
		root = hi->left;
		delete hi;
		return true;
	}
	if (hi->parent == nullptr){
		Node *temp = getSuccessorNode(hi->info);
		if (temp != nullptr){
			temp->left = hi->left;
			temp->left->parent = temp;
			root = hi->right;
			root->parent = nullptr;
			delete hi;
			return true;
		}
	}
	if (hi->info > hi->parent->info){
		Node *temp = getSuccessorNode(hi->info);
		if (temp != nullptr){
			temp->left = hi->left;
			temp->left->parent = temp;
			hi->parent->right = hi->right;
			hi->right->parent = hi->parent;
			delete hi;
			return true;
		}
		else{
			hi->parent->right = hi->left;
			if (hi->left != nullptr){
				hi->left->parent = hi->parent;
			}
			delete hi;
			return true;
		}
	}
	else if(hi->info < hi->parent->info){
		Node *temp = getSuccessorNode(hi->info);
		if (temp != nullptr && temp != hi->parent){
			temp->left = hi->left;
			temp->left->parent = temp;
			hi->parent->left = hi->right;
			hi->right->parent = hi->parent;
			delete hi;
			return true;
		}
		else{
			hi->parent->left = hi->left;
			if (hi->left != nullptr){
				hi->left->parent = hi->parent;
			}
			delete hi;
			return true;
		}
	}
	else{
		return false;
	}







	/*
	Node *temp = getSuccessorNode(hi->info);
	if (temp == nullptr || temp == hi->parent){
		temp = getPredecessorNode(hi->info);
		if (temp == nullptr || temp == hi->parent){
			if (hi->info > hi->parent->info){
				hi->parent->right = nullptr;
				delete hi;
				return true;
			}
			else{
				hi->parent->left = nullptr;
				delete hi;
				return true;
			}
		}
		else{
			if (hi->info > hi->parent->info){
				hi->parent->right = temp;
				delete hi;
				return true;
			}
			else{
				hi->parent->left = temp;
				delete hi;
				return true;
			}
		}
	}
	else{
		if (hi->info > hi->parent->info){
			hi->parent->right = temp;
			temp->left = hi->left;
			delete hi;
			return true;
		}
		else{
			hi->parent->left = temp;
			temp->left = hi->left;
			delete hi;
			return true;
		}
	}
	*/	
}
