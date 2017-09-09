#include "Stack.h"
using namespace std;

bool Stack::push(int value) {

	// create a stack node
	StackNode *stackNode = new StackNode(value);
	stackNode->link = topNode;
	topNode = stackNode;
	return true;
}

int Stack::pop() {
	int value;
	if (topNode == NULL) {
		cout << "Stack Underflow " << endl;
		return -1;
	} else {
		// note the return value
		int value = peek();

		// change the topNode
		topNode = topNode->link;
		
		return value;	
	}
}

bool Stack::isEmpty() {
	return (topNode == NULL);
}

int Stack::peek() {
	if (topNode == NULL) {
		return -1;
	} else {
		return topNode->value;
	}
}
