#include "Graph.hpp"

using namespace std;
// constructor
Graph::Graph(int V) :
	V(V),
	dist(V, INF), // distance vector
	adjacencyMatrix(V, list<pair<int, int> >(V))	
{};

// add edge, with source, dest and weight
void Graph::addEdge(int source, int dest, int weight) {
	adjacencyMatrix[source].push_back(make_pair(dest, weight));
	adjacencyMatrix[dest].push_back(make_pair(source, weight));
}

// shortest path algorithm using dijsktra
void Graph::dijkstraShortestPath(int source) {

	// create working set
	set< pair<int, int> > workingSet;

	// insert the source and initialize it with minimum distance
	// working set is created, with weights as first argument, to node as second
	workingSet.insert(make_pair(0, source));

	// set the distance of source to be "0"
	dist[source] = 0;

	while(!workingSet.empty()) {

		// get the minimum distance from the set and store it
		pair<int, int> currNode = *(workingSet.begin());

		// erase the node from the working set, use iterator pointer to the first node
		workingSet.erase(workingSet.begin());

		// get the vertex from the set
		int u = currNode.second;

		// iterator over all the adjacent vertices of the currNode
		list<pair<int, int> >::iterator itr;

		// iterate over the adjacency matrix
		for(itr=adjacencyMatrix[u].begin(); itr!=adjacencyMatrix[u].end(); ++itr) {
		
			int v = (*itr).first;
			int w = (*itr).second;

			// check if the ditance needs to be update
			if (dist[v] > dist[u] + w) {

				// update the working set
				// remove the value from the working set if it exits
				if (dist[v] != INF) {

					// will never reach here for the vertices that have been finalized
					workingSet.erase(workingSet.find(make_pair(dist[v], v)));
				}

				// update the distance, find new value
				dist[v] = dist[u] + w;

				// insert the updated distance in the working set
				workingSet.insert(make_pair(dist[v], v));
			}
		}
	}

	cout << "Vertex     " << "Distance from Source" << endl; 
	// print the distance set
	for(int i=0; i<V; i++) {
		cout <<i << "     " << dist[i] << endl;
	}
}
