#include "Queue.h"

int Queue::front() {
	if (!isEmpty()) {
		return frontNode->data;
	} else {
		return INT_MIN;
	}	
}

int Queue::rear() {
	if (!isEmpty()) {
		return rearNode->data;
	} else {
		return INT_MIN;
	}
}

void Queue::enqueue(int value) {
	
	//create a node
	QueueNode *newNode = new QueueNode(value);

	if (isEmpty()) {
		frontNode = newNode;
		rearNode = newNode;
		return;
	}

	// make the rear node point to the new node i.e. create a next link
	rearNode->next = newNode;

	// update the rear node
	rearNode = newNode;
}

int Queue::dequeue() {

	if (frontNode != rearNode) {
	
		// store the front node in tempNode
		QueueNode *tempNode = new QueueNode(frontNode);

		// move the front node
		frontNode = frontNode->next;

		// return the value
		return tempNode->data;
	} else {
		// store the front node in tempNode
		QueueNode *tempNode = new QueueNode(frontNode);

		frontNode = NULL;
		rearNode = NULL;
	
		return tempNode->data;	
	}
}

bool Queue::isEmpty() {
	return (rearNode == NULL && frontNode == NULL);
}
