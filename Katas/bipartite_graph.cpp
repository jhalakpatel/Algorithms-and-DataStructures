#include "header.hpp"
using namespace std;
#define V 4

enum Color {red, blue};
enum Status {not_visited, visited, visiting};

struct GraphVertex {
	int id;
	Color color;
	Status status = not_visited;
	struct Edge {
		GraphVertex *v;
		int weight;
	};
	vector<Edge> edges;
	GraphVertex(int i) {
		id = i;
	}
};

void addEdge(GraphVertex *u, GraphVertex *v, int weight) {
	u->edges.emplace_back(GraphVertex::Edge{v, weight});
	v->edges.emplace_back(GraphVertex::Edge{u, weight});
}

void createGraph(vector<GraphVertex*> *gptr) {
	vector<GraphVertex*> &Graph = *gptr;

	// bipartite case
/*
	addEdge(Graph[0], Graph[1], 1);
	addEdge(Graph[1], Graph[2], 1);
	addEdge(Graph[2], Graph[3], 1);
	addEdge(Graph[3], Graph[0], 1);
*/
	// not bipartite case
	addEdge(Graph[0], Graph[1], 1);
	addEdge(Graph[1], Graph[3], 1);
	addEdge(Graph[3], Graph[0], 1);

}

/*
 *	in strongly connected graph, visit the node, mark as visiting, assign a color = red,
 *	bfs - explore all the adj nodes, assign them color if not yet visited, if already visited, check if color is assigned 
 *  properly - if not break and return false
 */

bool bipartiteGraph(vector<GraphVertex*> Graph) {

	queue<GraphVertex*> bfsQueue;
	Graph[0]->color = red;		// assign color to starting node
	bfsQueue.emplace(Graph[0]);

	while(!bfsQueue.empty()){
			
		GraphVertex* u = bfsQueue.front();
		bfsQueue.pop();

		u->status = visiting;
		
		Color assignedColor = u->color==red?blue:red;	// assigned color should be different than neighbor
		
		for (int i=0; i<u->edges.size(); ++i) {
			GraphVertex *v = u->edges[i].v;
			if (v->status!=visited) {			// if no color assigned, assing assigned color
				v->color = assignedColor;
				bfsQueue.emplace(v);	// if the color assignment is ok, add it to the queue
				
			} else {
				// node is visited
				if (v->color != assignedColor) return false;
			}
		}

		u->status = visited;
	}

	return true;
}

int main() {
	vector<GraphVertex*> Graph(V);
	for (int i=0; i<V; ++i) {
		Graph[i] = new GraphVertex(i);
	}

	createGraph(&Graph);

	bool isBipartite = bipartiteGraph(Graph);

	if (isBipartite) {
		cout << "Graph is bipartite" << endl;
	} else {
		cout << "Graph is not bipartite" << endl;
	}	


	return 0;
}

