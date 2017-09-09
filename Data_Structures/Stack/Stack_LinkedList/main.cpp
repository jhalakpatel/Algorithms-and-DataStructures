#include <iostream>
#include "Stack.cpp"

using namespace std;

int main() {

	// create a stack object
	Stack *myStack = new Stack();

	cout << "created stack object " << endl;


	// populate stack
	for (int i=0; i < 5; i++) {
		myStack->push(i*i);
	}

	// will do stack overflow
	myStack->push(10);

	// peek value of the stack
	cout << myStack->peek() << endl;

	// pop some value 
	cout << myStack->pop() << endl;
	cout << myStack->pop() << endl;

    // peek  value now	
	cout << myStack->peek() << endl;

	// check if stack empty or not
	cout << myStack->isEmpty() << endl;

	
	cout << myStack->pop() << endl;
	cout << myStack->pop() << endl;
	cout << myStack->pop() << endl;
	cout << myStack->pop() << endl;	

	return 0;
}
