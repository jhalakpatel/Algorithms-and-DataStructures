#include <iostream>
#include <list>
#include <vector>
#include <set>

# define INF 0x3f3f3f3f

using namespace std;

class Graph {
	private:
		int V;

		// array to hold the shortest distances
		vector<int> dist;

		// adjacency matrix
		vector<list<pair<int, int> > > adjacencyMatrix;

	public:
		
		Graph(int V);
	
		void addEdge(int source, int dest, int weight);

		void dijkstraShortestPath(int source);
};
