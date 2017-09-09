class QueueNode {
	private:
		int data;
	public:
		QueueNode* next;

		// constructor to create a node with value
		QueueNode(int value) {
			this->data = value;
			next = NULL;
		}

		// constructor to create a node with another node
		QueueNode(QueueNode* newNode) {
			this->data = newNode->data;
			this->next = newNode->next;
		}

		QueueNode() {
			this->data = INT_MIN;
			this->next = NULL;
		}

		// will allow queue to access private data members
		friend class Queue;
};


class Queue : public QueueNode {
	private:
		QueueNode *frontNode;
		QueueNode *rearNode;	
	public:
		
		Queue() {
			frontNode = NULL;
			rearNode = NULL; 
		}
		
		void enqueue(int value);
		int dequeue();
		int front();
		int rear();
		bool isEmpty();

};
