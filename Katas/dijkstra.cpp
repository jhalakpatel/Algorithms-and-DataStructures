#include "header.hpp"

using namespace std;

#define V 9

struct GraphVertex {
	int id;
	struct Edge {
		GraphVertex *v;
		int weight;
	};
	vector<Edge> edges;
	GraphVertex(int i) {
		id = i;
	}
};


void addEdge(GraphVertex *u, GraphVertex *v, int weight) {
	u->edges.emplace_back(GraphVertex::Edge{v, weight});		// add directed edge from u --> v with a given weight
}
	
void createGraph(vector<GraphVertex*> *gptr) {
	vector<GraphVertex*> &Graph = *gptr;

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

struct comparator{
	bool operator() (pair<int, GraphVertex*> h1, pair<int, GraphVertex*> h2) {
		return h1.first < h2.first;
	}
};

vector<int> dijsktra(vector<GraphVertex*> Graph) {

	vector<int> DistanceFromSource(V, numeric_limits<int>::max());
	
	// IMP : hash function will be for c++ unordered_set, not for "set" --> set is a BST - it will have a custom comparator
	set<pair<int, GraphVertex*>, comparator> vertexSet;
	vertexSet.emplace(make_pair(0, Graph[0]));
	
	DistanceFromSource[0] = 0;	// source distance from itself

	// while the vertex set is not empty
	while(!vertexSet.empty()) {
		
		pair<int, GraphVertex*> p = *vertexSet.begin();	// get the smallest number
		vertexSet.erase(p);		// remove the element from the set
		
		int d = p.first;	// get distance from the source
		GraphVertex *u = p.second;	// node

		// iterate over the adjacent nodes
		for (int i=0; i<u->edges.size(); ++i) {
			GraphVertex *v = u->edges[i].v;
			int edgeWeight = u->edges[i].weight;

			if (d+edgeWeight < DistanceFromSource[v->id]) {
				// if the vertexSet contains the vertex with older weight
				auto itr = vertexSet.find(make_pair(DistanceFromSource[v->id], v));
				if (itr!=vertexSet.end()) {
					vertexSet.erase(itr);
				}

				DistanceFromSource[v->id] = d+edgeWeight;		// update the new distance
				vertexSet.emplace(make_pair(DistanceFromSource[v->id], v));	// add to the vertexSet for further processing
			}
		}
	}

	return DistanceFromSource;
}


int main() {

	vector<GraphVertex*> Graph(V);
	for (int i=0; i<V; ++i) {
		Graph[i] = new GraphVertex(i);
	}
	
	createGraph(&Graph);

	vector<int> DistanceFromSource;

	DistanceFromSource = dijsktra(Graph);

	cout <<"Distance from Single Source : "<<0<<endl;
	for (int i=0; i<V; ++i) {
		cout << "Vertex : "<<i<<" . Distance : "<<DistanceFromSource[i]<<endl;
	}

	return 0;
}
