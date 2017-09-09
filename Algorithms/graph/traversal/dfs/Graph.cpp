#include "Graph.h"

using namespace std;

Graph::Graph(int m_numOfVertices) : 
	numOfVertices(m_numOfVertices), 
	visited(m_numOfVertices, false),
	adjacencyMatrix(m_numOfVertices, vector<int>(m_numOfVertices))
	{
	};

void Graph::addEdge(int sourceVertex, int destVertex) {
	adjacencyMatrix[sourceVertex].push_back(destVertex);
}

void Graph::DFS(int sourceVertex) {

	// push the source to the stack, no need to intialize, thus "push" operation will work
	graphStack.push(sourceVertex);	

	// mark the node as visited
	visited[sourceVertex] = true;
	
	// print the output of traversal sequence	
	cout << sourceVertex << " ---> ";

	// traverse the adjacency list for the current node
	vector<int>::iterator s_itr;
	
	// iterate over the list
	for(s_itr=adjacencyMatrix[sourceVertex].begin();s_itr!=adjacencyMatrix[sourceVertex].end();++s_itr){
		// if node is not visited
		if (visited[*s_itr] == false) {
			
			// recursively call the graph DFS
			DFS(*s_itr);
		}
	}

	// remove the vertext from the stack
	graphStack.pop();

	return;
}


