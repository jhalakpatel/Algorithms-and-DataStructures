// basic graph data structure
#include <vector>
#include <stack>
using namespace std;

class Graph {
	private:
		int numOfVertices;
		vector<bool> visited;
		vector<int> recurStack;
		vector<vector<int> > adjacencyMatrix;
		bool detectCycleRecurseFunc(int sourceVertex);
	public:
		Graph(int sourceVertex);
		void addEdge(int source, int dest);
		bool detectCycle();
};
