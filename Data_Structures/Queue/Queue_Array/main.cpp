#include <iostream>
#include "Queue.cpp"

using namespace std;

int main() {

	Queue *myQueue = new Queue(2);

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
