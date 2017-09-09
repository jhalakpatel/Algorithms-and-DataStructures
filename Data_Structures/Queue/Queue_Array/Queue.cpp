#include "Queue.h"
using namespace std;

int Queue::front() {
	// queue is not empty
	if (!isEmpty())	return storage[frontIndex]; 
	return -1;
}

int Queue::rear() {
	// queue is not empty
	if (!isEmpty())	return storage[rearIndex]; 
	return -1;
}

void Queue::enqueue(int value) {
	if (isFull()) {
		cout << "Queue Overflow" << endl;
	} else {
		// increment rear in circular buffer order
		rearIndex = (rearIndex+1) % capacity;

		// enqueue the value
		storage[rearIndex] = value;

		// increase the size
		size++;
	}

}

int Queue::dequeue() {
	if (!isEmpty()){
		int value = storage[frontIndex];
		frontIndex = frontIndex + 1 % capacity;
		size--;
		return value;
	} else {
		return -1;
	}
}

bool Queue::isEmpty() {
	return (size == 0);
}

bool Queue::isFull() {
	return (size == capacity);
}
