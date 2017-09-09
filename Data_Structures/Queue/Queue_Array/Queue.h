class Queue {
	private:
		int *storage;
		int rearIndex;			// enqueue at rear
		int frontIndex;			// dequeue at front
		int capacity;
		int size;

		bool isFull();
		bool isEmpty();

	public:
		Queue(int capacity){
			this->capacity = capacity;
			storage = new int[capacity];
			rearIndex = capacity - 1; // important
			frontIndex = 0;
			size = 0;
		}

		void enqueue(int value);

		int dequeue();

		int front();

		int rear();
};
