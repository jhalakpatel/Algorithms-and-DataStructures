class Stack {
	private :
		int top;
		int capacity;
		int *storage;
	public :

		Stack() {
			top = -1;
			capacity = 5;
			storage = new int[5];
		}

		Stack(int size) {
			top = -1;
			capacity = size;
			storage = new int[size];
		}

		~Stack(){
			delete[] storage;
		}

		bool push(int);

		int pop();

		bool isEmpty();

		int peek();
};
