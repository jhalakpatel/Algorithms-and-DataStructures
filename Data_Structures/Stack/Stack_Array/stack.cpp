#include "Stack.h"

using namespace std;
int Stack::peek() {
	if (top < 0) {
		return 0;
	} else {
		return storage[top];
	}
}

bool Stack::push(int value) {
	if (top >= capacity-1) {
		cout << "Stack Overflow" << endl;
		return false;
	} else {
		storage[++top] = value;
		return true;
	}
}

int Stack::pop() {
	if (top < 0) {
		cout << "Stack Underflow" << endl;
		return 0;
	} else {
		return storage[top--];
	}
}

bool Stack::isEmpty(){
	return (top < 0);
}
