// basic graph data structure
#include <vector>
#include <stack>
using namespace std;

class Graph {
	private:
		int numOfVertices;
		vector<bool> visited;
		stack<int> nodeStack;
		vector<vector<int> > adjacencyMatrix;
		void topologicalRecurseFunc(int sourceVertex);
	public:
		Graph(int sourceVertex);
		void addEdge(int source, int dest);
		void topologicalSort();
};
