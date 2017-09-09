#include <vector>
#include <queue>
#include <list>

using namespace std;
class Graph {
	private:
		// number of vertices
		int numOfVertices;
	
		// adjacency matrix
		vector<vector<int> > adjacencyMatrix;

		// visted vertices data structure
		vector<bool> visted;
	
	public:
		Graph(int numOfVertices);

		void addEdge(int sourceVertex, int destVertex);

		void BFS(int sourceVertex);
};
