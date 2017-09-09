#include "Graph.hpp"
using namespace std;

Graph::Graph(int m_numOfVertices) : 
	numOfVertices(m_numOfVertices),
	visited(m_numOfVertices, false),
	adjacencyMatrix(m_numOfVertices, vector<int>(m_numOfVertices))
	{
	};

void Graph::addEdge(int source, int dest) {
	adjacencyMatrix[source].push_back(dest);
}

void Graph::topologicalRecurseFunc(int sourceVertex) {

	// mark the node as visted
	visited[sourceVertex] = true;
	
	// iterate over all the adjacent nodes
	vector<int>::iterator itr;
	for (itr=adjacencyMatrix[sourceVertex].begin(); itr!=adjacencyMatrix[sourceVertex].end(); ++itr) {
		// traverse to the node if not visted
		if (visited[*itr] == false) {
			topologicalRecurseFunc(*itr);
		}	
	}

	// found a node with all adjacent nodes traversed, push it in the stack
	nodeStack.push(sourceVertex);

	return;
}

void Graph::topologicalSort() {

	// recurse over all the vertices
	for(int i=0; i<numOfVertices; i++) {
		if (visited[i] == false) {
			topologicalRecurseFunc(i);
		}
	}

	// print the stack
	while(!nodeStack.empty()) {
		cout << nodeStack.top() << " ---> ";
		// remove the node from stack
		nodeStack.pop();
	}
}
