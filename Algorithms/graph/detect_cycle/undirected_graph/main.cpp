#include <iostream>
#include "DisjointSetGraph.cpp"

using namespace std;

int main() {
	
	int E = 3;
	int V = 3;

	// create graph with given edges and vertices
	DisjointSetGraph Graph(E, V);

	// connect the graph, with source and destination
	Graph.addEdge(0, 0, 1);
	Graph.addEdge(1, 1, 2);
	Graph.addEdge(2, 2, 0);

	if (Graph.isUndirectedGraphCyclic() == true) {
		cout << "Graph is Cyclic " << endl;
	} else {
		cout << "Graph is not Cyclic " << endl;
	}
	return 0;
}
