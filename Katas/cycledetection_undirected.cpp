#include "header.hpp"

using namespace std;

#define V 3

// simple GraphVertex Node
struct GraphVertex {
	int srcID;
	struct Edge {
		GraphVertex *src;
		GraphVertex *dest;
		int weight;
	};
	vector<Edge> edges;
	GraphVertex(int sID) {
		srcID = sID;
	}
};

void addEdge(GraphVertex *src, GraphVertex *dest, int weight) {
	src->edges.emplace_back(GraphVertex::Edge{src, dest, weight});;
}

void CreateGraph(vector<GraphVertex*> *GraphPtr) {
	vector<GraphVertex*> &Graph = *GraphPtr;
	
	// treate edges are undirected
	// 0--1 Edge
	addEdge(Graph[0], Graph[1], 1);

	// 1--2 Edge
	addEdge(Graph[1], Graph[2], 1);
	
	// 2--0 Edge
	addEdge(Graph[0], Graph[2], 1);

}

int find(vector<int> &parentSet, int src) {
	if (parentSet[src]==-1) return src;
	return find(parentSet, parentSet[src]);
}

void Union(int src, int dest, vector<int> *pSetPtr) {
	vector<int> &parentSet = *pSetPtr;
	parentSet[src] = dest;
}


bool HasCycle(vector<GraphVertex*> Graph) {
	
	// iterate over graph and get all the edges
	vector<GraphVertex::Edge> graphEdges;
	for (int i=0; i<V; ++i) {
		for (int j=0; j<Graph[i]->edges.size(); ++j) {
			graphEdges.emplace_back(GraphVertex::Edge{Graph[i]->edges[j].src, Graph[i]->edges[j].dest, Graph[i]->edges[j].weight});
		}
	}

	
	// create parent set corresponding to each vertex
	vector<int> parentSet(V, -1);

	for (int i=0; i<graphEdges.size(); ++i) {
		GraphVertex::Edge e = GraphVertex::Edge{graphEdges[i]};
		int src_parent = find(parentSet, e.src->srcID);
		int dest_parent = find(parentSet, e.dest->srcID);

		if (src_parent == dest_parent) {
			return true;	// cycle detected
		}

		Union(src_parent, dest_parent, &parentSet);
	}
	return false;
}


int main() {
	
	// represent graph as vector of GraphVertex
	vector<GraphVertex*> Graph(V);
	for (int i=0; i<V; ++i) {
		Graph[i] = new GraphVertex(i);
	}

	CreateGraph(&Graph);

	if (HasCycle(Graph)) {
		cout << "cycle detected" << endl;
	} else {
		cout << "no cycle detected" << endl;
	}

	return 0;
}
