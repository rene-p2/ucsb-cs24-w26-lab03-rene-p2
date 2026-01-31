#include "intbst.h"

#include <iostream>
using namespace std;

int main (){

	IntBST hi;
	hi.insert(24);
	hi.insert(22);
	hi.insert(44);
	hi.insert(12);
	hi.insert(300);
	hi.insert(32);
	hi.insert(10);
	hi.insert(9);
	hi.insert(2);
	hi.insert(8);
	cout << "BST: " << endl << "inorder: ";
	hi.printInOrder();
	cout << endl;
	cout << "BST: " << endl << " pre-order: ";
	hi.printPreOrder();
	cout << endl;
	cout << "BST: " << endl << " post-order: ";
        hi.printPostOrder();	
	cout << endl;
	cout << "sum: " << hi.sum() << endl;
	cout << "count: " << hi.count() << endl;

	cout << "predecessor of 24: " << hi.getPredecessor(24) << endl;
	cout << "predecessor of 22: " << hi.getPredecessor(22) << endl;
	cout << "predecessor of 44: " << hi.getPredecessor(44) << endl;
	cout << "predecessor of 300: " << hi.getPredecessor(300) << endl;

	cout << "contains 300? " << hi.contains(300) << endl;
	cout << "contains 1? " << hi.contains(1) << endl;

	cout << "successor of 24: " << hi.getSuccessor(24) << endl;
	cout << "successor of 22: " << hi.getSuccessor(22) << endl;
	cout << "successor of 44: " << hi.getSuccessor(44) << endl;
	cout << "successor of 300: " << hi.getSuccessor(300) << endl;

	cout << "removing 9: " << hi.remove(9) << endl;
	cout << "removing 1: " << hi.remove(1) << endl;

	cout << "contains 9? " << hi.contains(9) << endl;

	cout << "sum: " << hi.sum() << endl;

	return 0;
}
