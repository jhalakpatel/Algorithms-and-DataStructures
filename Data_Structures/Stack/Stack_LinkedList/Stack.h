class StackNode {
	public:
		int value;

		StackNode *link;

		// initialize stack node, with value and next pointer
		StackNode(int value) {
			this->value = value;
			link = NULL;
		}

		~StackNode() {
			link = NULL;
			value = -1;
		}
};

class Stack {
	private:
		StackNode *topNode;
	public:

		Stack() {
			topNode = new StackNode(-1);
			topNode->link = NULL;
		}

		bool push(int);

		bool isEmpty();

		int pop();

		int peek();
};
