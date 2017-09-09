#include "BST.h"
using namespace std;

template <class T>
void BST<T>::add(T value) {
	if (rootNode == NULL) {
		rootNode = new BSTNode<T>(value);
	} else {
		addHelper(rootNode, value);
	}
}

template <class T>
int BST<T>::nodesCount() {
	return nodesCountHelper(rootNode);
	
}

template <class T>
int BST<T>::treeHeight() {
	return treeHeightHelper(rootNode);
}


template <class T>
int BST<T>::maxPathSumHelper(BSTNode<T>* rootNode) {
	if (rootNode == NULL) return 0;		// recursion terminating condition

	cout << rootNode->data << " ---> ";

	// check the height
	if(treeHeightHelper(rootNode->left) > treeHeightHelper(rootNode->right)) {
		return rootNode->data + maxPathSumHelper(rootNode->left);
	} else {
		return rootNode->data + maxPathSumHelper(rootNode->right);
	}
}


template <class T>
void BST<T>::addHelper(BSTNode<T> *rootNode, T value) {

	// if root node is NULL, initialize root node	
	if (rootNode == NULL) {
		rootNode = new BSTNode<T>(value);
	} else {
		if (value < rootNode->data) {

			// check the left tree
			if (rootNode->left == NULL) {
				// found the end node; create a new node with value and assign to it
				rootNode->left = new BSTNode<T>(value);
			} else {
				// not reached the end node, recurse on the left node
				addHelper(rootNode->left, value);
			}
		
		} else {
		// if the value is more than the right node
			
			// check if reached the end
			if (rootNode->right == NULL) {
				// create a new node with given value
				rootNode->right = new BSTNode<T>(value);
			} else {
				// recurse to find the appropriate position
				addHelper(rootNode->right, value);
			}
		}
	}
}

template <class T>
int BST<T>::nodesCountHelper(BSTNode<T> *rootNode) {
	if (rootNode == NULL) return 0;
	return 1 + nodesCountHelper(rootNode->left) + nodesCountHelper(rootNode->right);

}


template <class T>
int BST<T>::treeHeightHelper(BSTNode<T> *rootNode) {
	if (rootNode == NULL) return 0;
	return 1 + max(treeHeightHelper(rootNode->left), treeHeightHelper(rootNode->right));
}


template <class T>
BSTNode<T>* BST<T>::minNodeFunc(BSTNode<T>* rootNode) {
	while(rootNode->left != NULL) rootNode = rootNode->left;
	return rootNode;
}


template <class T>
BSTNode<T>* BST<T>::deleteHelper(BSTNode<T> *rootNode, T value) {
	if (rootNode == NULL) return rootNode;
	if (value < rootNode->data) {
		rootNode->left = deleteHelper(rootNode->left, value);
	} else if (value > rootNode->data) {
		rootNode->right = deleteHelper(rootNode->right, value);
	} else {
		// rootNode->data == value
		if (rootNode->left == NULL && rootNode->right == NULL) {
			delete rootNode;
			rootNode = NULL;
		} else if (rootNode->left == NULL) {
			BSTNode<T> *tempNode = new BSTNode<T>(rootNode);
			rootNode = rootNode->right;
			delete tempNode;
		} else if (rootNode->right == NULL) {
			BSTNode<T> *tempNode = new BSTNode<T>(rootNode);
			rootNode = rootNode->left;
			delete tempNode;
		} else {
			// call min node function to get the minimum node
			BSTNode<T> *minNode = new BSTNode<T>(minNodeFunc(rootNode->right));
			rootNode->data = minNode->data;
			rootNode->right = deleteHelper(rootNode->right, rootNode->data);
			delete minNode;
		}	
	}
	return rootNode;
 }


template <class T>
BSTNode<T>* BST<T>::deleteValue(T value) {
	return deleteHelper(rootNode, value);
}

template <class T>
void BST<T>::printPreOrder(BSTNode<T> *rootNode) {
	
	if (rootNode == NULL) {
		return;
	} else {

		// print the node value
		cout << rootNode->data << " --> ";

		// traverse left
		printPreOrder(rootNode->left);

		//traverse right
		printPreOrder(rootNode->right);
	}
}

template <class T>
void BST<T>::printPostOrder(BSTNode<T> *rootNode) {
	
	if (rootNode == NULL) {
		return;
	} else {
		// traverse left
		printPostOrder(rootNode->left);

		//traverse right
		printPostOrder(rootNode->right);

		// print the node value
		cout << rootNode->data << " --> ";
	}
}

template <class T>
void BST<T>::printInOrder(BSTNode<T> *rootNode) {
	
	if (rootNode == NULL) {
		return;
	} else {
		// traverse left
		printInOrder(rootNode->left);

		// print the node value
		cout << rootNode->data << " --> ";

		//traverse right
		printInOrder(rootNode->right);
	}
}

template <class T>
void BST<T>::print(int printOrder) {
switch(printOrder) {
	case 1 :
		cout << endl << "In order traversal : " << endl;
		printInOrder(rootNode);
		break;
	case 2:
		cout << endl << "Pre order traversal : " << endl;
		printPreOrder(rootNode);
		break;
	case 3:
		cout << endl << "Post order traversal : " << endl;
		printPostOrder(rootNode);
		break;
	default:
		cout << endl << "In order traversal : " << endl;
		printInOrder(rootNode);
		break;
	}
}

template <class T>
int BST<T>::maxPathSum() {
	cout << endl << "Print Maximum Path " << endl;
	int max = maxPathSumHelper(rootNode);
	cout << endl << "Sum of Max Path : " << max << endl;
	return max;
}
