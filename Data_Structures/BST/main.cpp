#include <iostream>
#include "BST.cpp"
using namespace std;

int main() {
	BST<int> *bst = new BST<int>();

	cout << "created new BST instance successfully " << endl;

 	bst->add(11);
	bst->add(1);
	bst->add(6);
 	bst->add(-1);
 	bst->add(-10);
 	bst->add(100);
 	bst->print(1);
	bst->print(2);
	bst->print(3);
 	cout<<endl;
	cout<<"Nodes Count " <<	bst->nodesCount() << endl;
	cout<<"Tree Height " << bst->treeHeight() << endl;
	bst->maxPathSum();
	bst->deleteValue(1);
 	bst->print(1);
	return 0;
}
