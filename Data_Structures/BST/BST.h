template <class T>
class BSTNode {
	public:
		T data;
		BSTNode<T> *left;
		BSTNode<T> *right;

		BSTNode() {
			data = INT_MIN;
			left = NULL;
			right = NULL;
		}

		BSTNode(BSTNode<T>* newNode) {
			this->data = newNode->data;
			this->left = newNode->left;
			this->right = newNode->right;
		}

		BSTNode(T data, BSTNode<T> *left, BSTNode<T> *right) {
			this->data = data;
			this-left = left;
			this->right = right;
		}

		BSTNode(T data) {
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~BSTNode(){
			this->data = INT_MIN;
		}
};

template <class T>
class BST {
	private:
		// root node with template <T> 
		BSTNode<T>* rootNode;
		void addHelper(BSTNode<T>*,T);
		int treeHeightHelper(BSTNode<T>*);
		int nodesCountHelper(BSTNode<T>*);
		BSTNode<T>* deleteHelper(BSTNode<T>*,T);
		int maxPathSumHelper(BSTNode<T>*);
		BSTNode<T>* minNodeFunc(BSTNode<T>*);
	public:
		BST() {
			// root node with template <T>
			rootNode = NULL;
		}

		int maxPathSum();
		void add(T);
	   	BSTNode<T>* deleteValue(T);
		BSTNode<T> search(T);
		int nodesCount();
		int treeHeight();
		void print(int);
		void printPostOrder(BSTNode<T> *);
		void printPreOrder(BSTNode<T> *);
		void printInOrder(BSTNode<T> *);
};
