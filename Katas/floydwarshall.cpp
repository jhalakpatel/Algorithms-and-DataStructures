#include "header.hpp"

using namespace std;

#define V 4

struct Edge {
	int u;
	int v;
	int weight;
};

void createGraphEdges(vector<Edge> *gptr) {
	vector<Edge> & GraphEdges = *gptr;

/*
	GraphEdges.emplace_back(Edge{0, 1, -1});
	GraphEdges.emplace_back(Edge{0, 2, 4});
	GraphEdges.emplace_back(Edge{1, 2, 3});
	GraphEdges.emplace_back(Edge{1, 3, 2});
	GraphEdges.emplace_back(Edge{1, 4, 2});
	GraphEdges.emplace_back(Edge{3, 2, 5});
	GraphEdges.emplace_back(Edge{3, 1, 1});
	GraphEdges.emplace_back(Edge{4, 3, -3});
*/
	GraphEdges.emplace_back(Edge{0, 3, 10});
	GraphEdges.emplace_back(Edge{0, 1, 5});
	GraphEdges.emplace_back(Edge{1, 2, 3});
	GraphEdges.emplace_back(Edge{2, 3, 1});

}

vector<vector<int>> floydwarshall(vector<Edge>& GraphEdges) {

	// initialize distance vector
	vector<vector<int>> distances(V, vector<int>(V, numeric_limits<int>::max()));

	// mark the distance == 0, where source == destination
	for (int i=0; i<V; ++i) {
		for (int j=0; j<V; ++j) {
			if (i==j) {
				distances[i][j] = 0;
			}
		}
	}

	// iterate over all the vertices - making them origin
	for (int i=0; i<V; ++i) {

		// relax one edge a time - till V-1 edges, length of maximum/longest path
		for (int j=0; j<V-1; ++j) {

			// iterate over all the edges in the graph
			for (int k=0; k<GraphEdges.size(); ++k) {
				
				int src = GraphEdges[k].u;
				int dest = GraphEdges[k].v;
				int weight = GraphEdges[k].weight;
	
				// i - is the origin
				if (distances[i][dest] > distances[i][src] + weight && distances[i][src] != numeric_limits<int>::max()) {
					distances[i][dest] = distances[i][src] + weight;
				}
			}
		}
	}

	return distances;
}

int main() {
	
	vector<Edge> GraphEdges;

	createGraphEdges(&GraphEdges);	

	vector<vector<int>> DistanceFromSources;

	DistanceFromSources = floydwarshall(GraphEdges);

	for (int i=0; i<V; ++i) {
		cout <<"Distance from Single Source : "<<i<<endl;
		for (int j=0; j<V; ++j) {
			cout << "Vertex : "<<j<<" Distance from Vertex : "<<i<<" is : "<<DistanceFromSources[i][j]<<endl;
		}
		cout << endl;
	}

	return 0;
}
