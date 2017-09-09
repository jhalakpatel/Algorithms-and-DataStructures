#include "header.hpp"

using namespace std;

#define V 5

struct GraphVertex {
	int id;
	struct Edge {
		GraphVertex *u;		
		GraphVertex *v;
		int weight;
	};
	vector<Edge> edges;
	GraphVertex(int i) {
		id = i;
	}
};

/*
// create a directed graph
void addEdge(GraphVertex *u, GraphVertex *v, int weight) {
	u->edges.emplace_back(GraphVertex::Edge{v, weight});
}

void createGraph(vector<GraphVertex*> *gptr){
	addEdge(Graph[0], Graph[1], 4 );
	addEdge(Graph[0], Graph[7], 8);

	addEdge(Graph[1], Graph[0], 4);
	addEdge(Graph[1], Graph[7], 11);
	addEdge(Graph[1], Graph[2], 8);

	addEdge(Graph[2], Graph[1], 8);
	addEdge(Graph[2], Graph[8], 2);
	addEdge(Graph[2], Graph[5], 4);
	addEdge(Graph[2], Graph[3], 7);

	addEdge(Graph[3], Graph[2], 7);
	addEdge(Graph[3], Graph[5], 14);
	addEdge(Graph[3], Graph[4], 9);

	addEdge(Graph[4], Graph[3], 9);
	addEdge(Graph[4], Graph[5], 10);

	addEdge(Graph[5], Graph[2], 4);
	addEdge(Graph[5], Graph[3], 14);
	addEdge(Graph[5], Graph[4], 10);
	addEdge(Graph[5], Graph[6], 2);

	addEdge(Graph[6], Graph[8], 6);
	addEdge(Graph[6], Graph[7], 1);
	addEdge(Graph[6], Graph[5], 2);

	addEdge(Graph[7], Graph[0], 8);
	addEdge(Graph[7], Graph[1], 11);
	addEdge(Graph[7], Graph[8], 7);
	addEdge(Graph[7], Graph[6], 1);

	addEdge(Graph[8], Graph[2], 2);
	addEdge(Graph[8], Graph[7], 7);
	addEdge(Graph[8], Graph[6], 6);
}
*/

void createGraphAsEdges(vector<GraphVertex::Edge> *gedgeptr, vector<GraphVertex*> &Graph) {
	vector<GraphVertex::Edge> & GraphEdges = *gedgeptr;
	GraphEdges.emplace_back(GraphVertex::Edge{Graph[0], Graph[1], -1});
	GraphEdges.emplace_back(GraphVertex::Edge{Graph[0], Graph[2], 4});
	GraphEdges.emplace_back(GraphVertex::Edge{Graph[1], Graph[2], 3});
	GraphEdges.emplace_back(GraphVertex::Edge{Graph[1], Graph[3], 2});
	GraphEdges.emplace_back(GraphVertex::Edge{Graph[1], Graph[4], 2});
	GraphEdges.emplace_back(GraphVertex::Edge{Graph[3], Graph[2], 5});
	GraphEdges.emplace_back(GraphVertex::Edge{Graph[3], Graph[1], 1});
	GraphEdges.emplace_back(GraphVertex::Edge{Graph[4], Graph[3], -3});
}

/* Dijkstra does not work for negative edges, but bellman ford works with negative edges
 *	assuming - no negative weight cycle
 *
 *	if we relax the egdes for V-1 times, any graph with V vertices, maximum simple path will have V-1 edges
 *
 *	it calculates shortest distance for shortest path having i edges, in ith iteration, 
 *	atmost in any path can have v-1 edges, thus will have shortest distance for shortest path with V-1 edges will need V-1 iteration
 *
 */ 
vector<int> bellmanford(vector<GraphVertex::Edge> GraphEdges, GraphVertex *src) {

	vector<int> distanceFromSource(V, numeric_limits<int>::max());
	distanceFromSource[src->id] = 0;	// distance of source from itself
	
		
	// relaxing all the the edges V-1 times 
	for (int i=0; i<V-1; ++i) {

		// for all the edges
		for (int j=0; j<GraphEdges.size(); ++j) {
		
			// get edge variables	
			GraphVertex *src = GraphEdges[j].u;
			GraphVertex *dest = GraphEdges[j].v;
			int weight = GraphEdges[j].weight;

			// if distance is more, update the distance
			if (distanceFromSource[dest->id] > distanceFromSource[src->id] + weight) {
				distanceFromSource[dest->id] = distanceFromSource[src->id] + weight;
			}

		}
	}
	
	return distanceFromSource;
}

int main() {

	vector<GraphVertex*> Graph(V);
	for (int i=0; i<V; ++i) {
		Graph[i] = new GraphVertex(i);
	}

	//createGraph(&Graph);

	vector<GraphVertex::Edge> GraphEdges;

	createGraphAsEdges(&GraphEdges,Graph);

	vector<int> DistanceFromSource;

	DistanceFromSource = bellmanford(GraphEdges, Graph[0]);

	cout <<"Distance from Single Source : "<<0<<endl;
	for (int i=0; i<V; ++i) {
		cout << "Vertex : "<<i<<" . Distance : "<<DistanceFromSource[i]<<endl;
	}

	return 0;
}
