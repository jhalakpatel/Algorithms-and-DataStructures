#include "BinaryTree.cpp"

using namespace std;
int main() {

	// create BinaryTree Root Node with value 1
	BinaryTree btree(1);

	btree.rootNode->left = new BNode(2);
	btree.rootNode->right = new BNode(3);
	btree.rootNode->left->left = new BNode(4);
	btree.rootNode->left->right = new BNode(5);

	// travere the binary tree inOrderTraversal
	btree.inOrderTraversal();

	return 0;
}
