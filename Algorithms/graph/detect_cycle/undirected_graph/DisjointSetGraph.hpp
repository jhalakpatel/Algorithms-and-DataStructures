#include <vector>
using namespace std;

class Edge {
	public:
		int source;
		int dest;
};

class DisjointSetGraph {
	private:
		// vector to hold all the edges in a graph
		vector<Edge> EdgeVec;		

		int numEdge;

		int numVertex;

		// parent vec
		vector<int> parentVec;
		
	public:
		// constructor to initialize DisjointGraph data structure
		DisjointSetGraph(int numEdge, int numVertex);

		// find function
		int Find(int vertex);

		// Union function
		void Union(int vertex_1, int vertex_2);

		// function to find cycle
		bool isUndirectedGraphCyclic();

		void addEdge(int edge, int source, int dest);
};
