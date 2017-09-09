#include "header.hpp"

using namespace std;

#define V 5

enum Status {not_visited, visiting, visited};

class GraphVertex {
	public:
	int src;
	Status status = not_visited;
	vector<pair<GraphVertex*, int>> EdgesWithWeight;
	GraphVertex(int s) {
		src = s;
	}
};

void addEdge(GraphVertex* u, GraphVertex* v, int weight) {
	u->EdgesWithWeight.emplace_back(v, weight);
}


void createGraph(vector<GraphVertex*> *GraphPtr) {
	vector<GraphVertex*> &Graph = *GraphPtr;

	for (int i=0; i<Graph.size(); ++i) {
		Graph[i] = new GraphVertex(i);
	}

	addEdge(Graph[0], Graph[1], 1);
	addEdge(Graph[0], Graph[4], 1);
	addEdge(Graph[1], Graph[0], 1);
	addEdge(Graph[1], Graph[4], 1);
	addEdge(Graph[1], Graph[2], 1);
	addEdge(Graph[1], Graph[3], 1);
	addEdge(Graph[2], Graph[1], 1);
	addEdge(Graph[2], Graph[3], 1);
	addEdge(Graph[3], Graph[1], 1);
	addEdge(Graph[3], Graph[4], 1);
	addEdge(Graph[3], Graph[2], 1);
	addEdge(Graph[4], Graph[3], 1);
	addEdge(Graph[4], Graph[0], 1);
	addEdge(Graph[4], Graph[1], 1);
}

void bfs(GraphVertex* g) {
	queue<GraphVertex*> bfsQueue;
	bfsQueue.emplace(g);
	g->status = visiting;
	while(!bfsQueue.empty()) {
		GraphVertex *u = bfsQueue.front();
		bfsQueue.pop();
		cout << "Vertex : "<<u->src<<endl;
		// iterate over the adjacent 
		vector<pair<GraphVertex*, int>>::iterator geitr;
	
		for (geitr=u->EdgesWithWeight.begin(); geitr!=u->EdgesWithWeight.end(); ++geitr) {
			// if the node is not visited
			if (geitr->first->status==not_visited) {
				geitr->first->status = visiting;		// currently visiting the node	
				bfsQueue.emplace(geitr->first);
			}
		}
		u->status = visited;		// mark node as visited
	}
}

int main(){
	
	// create a simple graph
	vector<GraphVertex*> Graph(5);
	createGraph(&Graph);

	// start bfs
	bfs(Graph[0]);

	return 0;
}
