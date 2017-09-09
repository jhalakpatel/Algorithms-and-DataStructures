#include "LinkedList.hpp"
using namespace std;

Node::Node(int data) {
	this->data = data;
	this->next = NULL;
}

Node::Node(Node* node) {
	this->data = node->data;
	this->next = node->next;
}

LinkedList::LinkedList(Node* head) {
	this->head = head;
}

void LinkedList::appendToTail(int data) {
	// create a new node
	Node *newNode = new Node(data);

	// no head node
	if (head == NULL) {
		head = newNode;
	} else {
		
		// get the current node
		Node *curr = head;
		while(curr->next!=NULL) {
			curr = curr->next;
		}

		cout << "Adding Node with value : "<<newNode->data << endl;

		curr->next = newNode;
	}
}

void LinkedList::deleteNode(int data) {
	Node *curr = head;
	Node *prev = head;

	if (curr->data == data) {
		// head changed
		head = head->next;
		cout << "Node found. Removing Node." << endl;
		return;
	}

	// iterate through the list to find the node
	while(curr != NULL) {
		if (curr->data == data) {
			prev->next = curr->next;
			cout << "Node found. Removing Node." << endl;
			return;
		}
		prev = curr;
		curr = curr->next;
	}

	if (curr == NULL) {	
		cout << "Node not found" << endl;
	}
}
