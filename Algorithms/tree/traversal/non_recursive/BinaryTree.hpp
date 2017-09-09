#include <iostream>
#include <stack>
using namespace std;

class BNode {
	public:
		int data;
		BNode* left;
		BNode* right;
		BNode(int data);
		BNode(BNode* initNode);
};

class BinaryTree {
	public:
		BNode* rootNode;
		stack<BNode> BNodeStack;
		BinaryTree(int data);
		void inOrderTraversal();
};
