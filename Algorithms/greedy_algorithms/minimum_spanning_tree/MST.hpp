#include <vector>
using namespace std;

class Edge {
	public:
		int source;
		int dest;
		int weight;
};

class DisjointSet {
	public:
		int parent;	// store parent of current node 
		int rank;	// store rank of current node
};

class MST {
	private:
		int E;	// edges
		int V;	// vertices
		vector<Edge> Edges;	// store all the edges
		vector<DisjointSet> DisjointSetVec; // to store parent child and rank relationship
		int findRoot(int v);
		void findRankUnion(int v1, int v2);	
	public:
		MST(int E, int V);
		vector<Edge> MSTVec; // store minimum spanning tree
		void addEdge(int edge, int source, int dest, int weight);
		bool isCyclic(Edge egde);
		
		// Kruskals MST Implementation
		void KruskalMST();
};
