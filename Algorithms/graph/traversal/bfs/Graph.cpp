#include "Graph.h"
using namespace std;

Graph::Graph(int m_numOfVertices) : numOfVertices(m_numOfVertices), 
				visted(m_numOfVertices, false), 
				adjacencyMatrix(m_numOfVertices, vector<int>(m_numOfVertices)){
};

void Graph::addEdge(int sourceVertex, int destVertex){
	// connect source Vertex and destination vertex
	adjacencyMatrix[sourceVertex].push_back(destVertex);
}

void Graph::BFS(int sourceVertex) {
	
	// to store nodes/vertices to traverse
	list<int> bfsQueue;
	
	// populate the queue
	bfsQueue.push_back(sourceVertex);

	int visitingVertex;

	cout << endl;

	while(!bfsQueue.empty()) {
			
		// pop up the vertex which is getting visted
		visitingVertex = bfsQueue.front();
		// remove the visted vertex
		bfsQueue.pop_front();

		cout << visitingVertex << " ---> ";

		// mark as visted
		visted[visitingVertex] = true;

		// iterate over the adjacent vertex
		vector<int>::iterator itr;
			
		for(itr=adjacencyMatrix[visitingVertex].begin(); itr != adjacencyMatrix[visitingVertex].end(); ++itr){
			// if the vertex is not visited before
			if (!visted[*itr]) {
				// mark as visited
				visted[*itr] = true;

				// store it in the queue to be visited next in FIFO order
				bfsQueue.push_back(*itr);
			}
		}
	}	
}
