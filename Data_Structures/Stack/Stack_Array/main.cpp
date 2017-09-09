#include <iostream>
#include "Stack.cpp"

using namespace std;

int main() {

	// create stack with capacity 5
	Stack *myStack = new Stack(5);

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
}
