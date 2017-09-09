#include "MST.hpp"

using namespace std;

// Helper function eg. comparator, prints etc
int comparator(Edge e1, Edge e2) {
	// return true if e1.
	return e1.weight < e2.weight;
}

MST::MST(int V, int E) :
	E(E),
	V(V),
	Edges(E),			
	MSTVec(V-1), 			// Edges = V -1 to connect all the V
	DisjointSetVec(V)	// Disjoint DS for each vertex
{
	for (int i=0; i<V; i++) {
		DisjointSetVec[i].parent = -1;
		DisjointSetVec[i].rank = 0;
	}
};

void MST::addEdge(int edge, int source, int dest, int weight) {
	Edges[edge].source = source;
	Edges[edge].dest = dest;
	Edges[edge].weight = weight;
}


int MST::findRoot(int v) {
	// if parent is found
	if (DisjointSetVec[v].parent == -1) return v;

	// if parent no found recurse
	return findRoot(DisjointSetVec[v].parent);
}

void MST::findRankUnion(int v1, int v2) {

	int v1_root = findRoot(v1);
	int v2_root = findRoot(v2);

	if (DisjointSetVec[v1_root].rank > DisjointSetVec[v2_root].rank){
		// attach v2_root to v1_root; no change in rank
		DisjointSetVec[v2_root].parent = v1_root;
	} else if (DisjointSetVec[v2_root].rank > DisjointSetVec[v1_root].rank) {
		// attach v1_root to v2_root; no change in rank
		DisjointSetVec[v1_root].parent = v2_root;
	} else {
		// if both are equal, attach v1 to v2
		DisjointSetVec[v1_root].parent = v2_root;
		// increase v2 rank by 1
		DisjointSetVec[v2_root].rank = DisjointSetVec[v2_root].rank + 1;
	}
}

bool MST::isCyclic(Edge newEdge) {

	//cout << "cyclic or not" << endl;
	
	// get new edge source and dest
	int x = newEdge.source;
	int y = newEdge.dest;

	//cout << "find source and dest " << endl;

	int x_root = findRoot(x);
	int y_root = findRoot(y);

	// adding the edge will create cycle in MST, do not add
	return (x_root == y_root);
}

void MST::KruskalMST() {

	// sort edges in non decreasing order
	sort(Edges.begin(), Edges.end(), comparator);

	int e = 0;
	int nextedge = 0;

	while(e < V-1) {
		// check if adding the edge will result in cycle or not
		if (!isCyclic(Edges[nextedge])) {

			// get source and destination for the given edge
			int x = Edges[nextedge].source;
			int y = Edges[nextedge].dest;

			// create rank union for the vertices of the edge
			findRankUnion(x, y);

			// append the in MST data structure
			MSTVec[e] = Edges[nextedge];

			// add edges, increament the edge count
			e++;
		}

		// go to nexr edge
		nextedge++;
	}
}


