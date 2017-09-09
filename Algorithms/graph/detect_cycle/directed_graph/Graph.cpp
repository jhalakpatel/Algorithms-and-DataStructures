#include "Graph.hpp"
using namespace std;

Graph::Graph(int m_numOfVertices) : 
	numOfVertices(m_numOfVertices),
	visited(m_numOfVertices, false),
	recurStack(m_numOfVertices, false),
	adjacencyMatrix(m_numOfVertices, vector<int>(m_numOfVertices))
	{
	};

void Graph::addEdge(int source, int dest) {
	adjacencyMatrix[source].push_back(dest);
}

bool Graph::detectCycleRecurseFunc(int sourceVertex) {

	if (visited[sourceVertex] == false) {
		
		// mark node as visited
		visited[sourceVertex] = true;

		// put node in recursion stack
		recurStack[sourceVertex] = true;	

		// iterate over the the
		vector<int>::iterator itr;

		for(itr=adjacencyMatrix[sourceVertex].begin(); itr!=adjacencyMatrix[sourceVertex].end(); ++itr) {

			// if node is not visited
			if ((visited[*itr] == false) && detectCycleRecurseFunc(*itr)) {
				return true;
			} else if (recurStack[*itr]) {
				// if not is already visited and in the current recursion stack
				return true;
			}
		}
	}

	// remove the node from the current recursion stack
	recurStack[sourceVertex] = false;

	return false;
}

bool Graph::detectCycle() {

	// recurse over all the vertices
	for(int i=0; i<numOfVertices; i++) {
		// visit every node to find out if it result in cycle or not
		if (detectCycleRecurseFunc(i) == true) return true;
	}
	return false;
}
