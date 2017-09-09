#include <iostream>
#include "Queue.cpp"

using namespace std;
int main() {

	// create Queue instance
	Queue *myQueue = new Queue();

	myQueue->enqueue(2);

	cout << myQueue->front() << endl;
	cout << myQueue->rear() << endl;
	
	myQueue->enqueue(3);

	cout << myQueue->front() << endl;
	cout << myQueue->rear() << endl;
	
	myQueue->enqueue(4);

	cout << myQueue->front() << endl;
	cout << myQueue->rear() << endl;

	cout << myQueue->dequeue() << endl;
	cout << myQueue->dequeue() << endl;
	cout << myQueue->dequeue() << endl;
	
	return 0;
}
