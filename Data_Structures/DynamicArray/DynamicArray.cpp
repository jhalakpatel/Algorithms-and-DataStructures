#include "DynamicArray.h"

void DynamicArray::rangeCheck(int index){
	if (index < 0 || index >= size)
		throw "out of bounds";
}

void DynamicArray::setAt(int index, int value) {
	// check range
	rangeCheck(index);

	// add value at index
	storage[index] = value;
}

int DynamicArray::getAt(int index) {
	rangeCheck(index);
	return storage[index];
}

void DynamicArray::insertAt(int index, int value) {
	
	// check range before inserting
	if (index <0 || index > size) throw "out of bounds";

	int newCapacity = size + 1;
	// ensure capacity
	ensureCapacity(newCapacity);

	int moveItems = size - index;

	if (moveItems > 0){
		memmove(storage + index + 1, storage + index, sizeof(int) * moveItems);
	}

	// insert the new value
	storage[index] = value;

	// incrase the size
	size++;
}

int DynamicArray::removeAt(int index) {

	// check range before removing
	rangeCheck(index);

	// number of items to move
	int moveItems = size - index - 1;

	// item getting removed
	int removedItem = storage[index];


	if (moveItems > 0) {
		memmove(storage + index, storage + index + 1, sizeof(int) * moveItems);

	}

	// decrease the size
	size--;

	// pack() to make sure we are not wasting memory
	pack();

	return removedItem;
}

void DynamicArray::ensureCapacity(int minCapacity) {

	// check if increase in capacity is required
	if (minCapacity > capacity) {
		int newCapacity	= capacity * 3 / 2 + 1;
		if (newCapacity > minCapacity) {
			setCapacity(newCapacity);
		} else {
			setCapacity(minCapacity);
		}
	}
}

void DynamicArray::setCapacity(int newCapacity) {

	// create memory space of the new memory
	int *newStorage = new int[newCapacity];

	// reallocate the old memory to new memory
	memcpy(newStorage, storage, sizeof(int) * size);

	// free up old memory
	delete[] storage;

	// update the new capacity
	capacity = newCapacity;

	// assign the new storage
	storage = newStorage;
}

void DynamicArray::pack() {

	// check a predfined limit for capacity
	if (size <= capacity/2) {

		// get new capacity based on the size
		int newCapacity = size * 3 / 2 + 1;

		// set new capacity
		setCapacity(newCapacity);
	}
}

void DynamicArray::trim() {
	// trim the capacity to the current size
	int newCapacity = size;

	// set the capacity
	setCapacity(newCapacity);
}




