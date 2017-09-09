#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main() {

	// create a head node
	Node *head = new Node(10);

	// create linked list head
	LinkedList *LL = new LinkedList(head);

	LL->appendToTail(11);
	LL->appendToTail(12);
	LL->appendToTail(13);
	LL->deleteNode(12);
	LL->deleteNode(12);
	LL->deleteNode(10);
	LL->deleteNode(13);
	return 0;
}
