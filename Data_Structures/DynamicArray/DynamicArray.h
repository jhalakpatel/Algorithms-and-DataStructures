class DynamicArray {
	private:
		int size;
		int capacity;
		int *storage;

		// check the capacity before adding a new element
		void ensureCapacity(int minimumCapacity);

		// check the capacity after removing a element and reduce the capacity
		void pack();

		// check the range
		void rangeCheck(int index);

		// set new capacity
		void setCapacity(int newCapacity);

	public:
		// constructor
		DynamicArray(){
			capacity = 10;
			size = 0;
			storage = new int[capacity];
		}

		DynamicArray(int capacity){
			this->capacity = capacity;
			size = 0;
			storage = new int[capacity];
		}
			

		// destructor
		~DynamicArray(){
			delete[] storage;
		}

		// get value at index
		int getAt(int index);

		// set value at a given index
		void setAt(int index, int value);

		// Insert at given index
		void insertAt(int index, int value);

		// remove at a given index
		int removeAt(int index);

		void trim();
};


