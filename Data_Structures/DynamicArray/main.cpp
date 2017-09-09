#include <iostream>
#include "DynamicArray.cpp"

using namespace std;
int main() {

	cout << "---- Staring the DynamicArray Class Check" << endl;

	int capacity = 6;

	// create instance of the DynamicArray : with capacity = 6
	DynamicArray *myVector = new DynamicArray(capacity);

	cout << "---- Done creating a DynamicArray Vector " << endl;

	// insert some elements
	for (int i=0; i < capacity; i++){
		myVector->insertAt(i, i *i);
	}

	cout << "---- Done inserting a DynamicArray Vector " << endl;


	// get the elements
	for (int i=0; i < capacity; i++) {
		cout << "Value at index : " << i  << " is = " << myVector->getAt(i) << endl;
	}


	// set some elements with new value
	for (int i=0; i < capacity; i++){
		myVector->setAt(i, i * i * i);
	}

    // get the elements
	for (int i=0; i < capacity; i++) {
		cout << "Value at index : " << i  << " is = " << myVector->getAt(i) << endl;
	}

	cout << "---- Done Setting a DynamicArray Vector " << endl;
	
	// insert item at index "2"
	myVector->insertAt(2, 1024);

	// remove item at index "2"
	cout << "Item removed : " << myVector->removeAt(2) << endl;


	// trim the storage
	myVector->trim();

	return 0;
}
