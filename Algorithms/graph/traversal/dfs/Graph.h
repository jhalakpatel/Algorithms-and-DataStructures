#include <vector>
#include <stack>

using namespace std;

class Graph {
	private:
		int numOfVertices;
		vector<bool> visited;
		stack<int> graphStack; 
		vector<vector<int> > adjacencyMatrix;
	public:
		Graph(int numOfVertices);
		void addEdge(int sourceVertex, int destVertex);
		void DFS(int sourceVertex);
};
