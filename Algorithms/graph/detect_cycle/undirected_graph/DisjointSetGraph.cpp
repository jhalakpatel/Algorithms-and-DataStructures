#include "DisjointSetGraph.hpp"

DisjointSetGraph::DisjointSetGraph(int m_numEdge, int m_numVertex) :
	numEdge(m_numEdge),
	numVertex(m_numVertex),
	EdgeVec(m_numEdge),
	parentVec(m_numVertex, -1)	// -1 represent the parent is the index/vertex iteself,
   								// any other number points to parent vertrex
	{
	};


void DisjointSetGraph::addEdge(int edge, int source, int dest) {
	EdgeVec[edge].source = source;
	EdgeVec[edge].dest = dest;
}

int DisjointSetGraph::Find(int vertex) {

	// if parent == -1, means reached the root, return the index
	if (parentVec[vertex] == -1) return vertex;
	
	// stores parent index, call find recursively to find the parent (recursively)
	return Find(parentVec[vertex]);
};

void DisjointSetGraph::Union(int vertex_1, int vertex_2) {

	// get parent vertex from the given vertex
	int x_root = Find(vertex_1);
	int y_root = Find(vertex_2);

	// make y_root as parent of x_root
	parentVec[x_root] = y_root;
};

bool DisjointSetGraph::isUndirectedGraphCyclic() {

	// iterate over all the edges
	//
	// get the edge iterator
	vector<Edge>::iterator e_itr;
	
	for(e_itr=EdgeVec.begin(); e_itr!=EdgeVec.end(); ++e_itr) {
		
		// get vertices from the edge	
		int x = e_itr->source;  // *e_itr->source
		int y = e_itr->dest;    // *e_itr->dest

		// find parent of the vertices
		int x_root = Find(x);
		int y_root = Find(y);

		if (x_root == y_root) return true;

		// find the union of x_root and y_root
		Union(x_root, y_root);
	}

	// after iterating all the edge and considering all vertices relationship
	// no cycle is found. 
	return false;
}
