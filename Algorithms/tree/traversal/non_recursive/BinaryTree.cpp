#include "BinaryTree.hpp"
using namespace std;

BNode::BNode(int data) {
	this->data = data;
	this->left = NULL;
	this->right = NULL;
}

BNode::BNode(BNode* initNode) {
	this->data = initNode->data;
	this->left = initNode->left;
	this->right = initNode->right;
}

BinaryTree::BinaryTree(int data) {
	// create the root node with data
	rootNode = new BNode(data);	
}

void BinaryTree::inOrderTraversal() {
	BNode* currNode = rootNode;

	// iterate till the BNode Stack is empty and currNode == NULL
	while(!BNodeStack.empty() || !(currNode == NULL)) {
	
		// push all the left nodes till no left nodes to traverse
		while(currNode != NULL) {
			BNodeStack.push(*currNode);
			currNode = currNode->left;
		}

		// now reach left most node
		BNode* poppedNode = new BNode(BNodeStack.top());
		cout << poppedNode->data << endl;
		BNodeStack.pop();

		// set the curr node to the right of the popped node
		currNode = poppedNode->right;
	}		
}
