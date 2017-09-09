#include "header.hpp"

using namespace std;

#define V 5

struct GraphVertex {
	int id;
	GraphVertex(int gid):id(gid) {} // initialization list
	struct Edge {
		GraphVertex *u;
		GraphVertex *v;
		int weight;
		Edge(GraphVertex *u, GraphVertex *v, int weight=1) : u(u), v(v) {}		
	};
	vector<Edge> edges;
};

void addEdge(GraphVertex* u, GraphVertex *v) {
	u->edges.emplace_back(GraphVertex::Edge{u,v});		// graph is undirected, so add edges in both the directions
	v->edges.emplace_back(GraphVertex::Edge{v,u});
}


void createGraph(vector<GraphVertex*> *gptr) {
	vector<GraphVertex*> &Graph = *gptr;
	addEdge(Graph[0], Graph[1]);
	addEdge(Graph[0], Graph[2]);
	addEdge(Graph[1], Graph[2]);
	addEdge(Graph[1], Graph[3]);
	addEdge(Graph[2], Graph[3]);
	addEdge(Graph[3], Graph[4]);
}

vector<int> greedyColoring(vector<GraphVertex*> Graph) {

	vector<int> Colors(V, -1);		// final color assignment
	vector<bool> availableColor(V, true);	// initially all the colors are available
	
	Colors[0] = 0;	// assign color to first vertex
	
	for (int k=1; k<V; ++k) {

		GraphVertex *f = Graph[k];

		// iterate through all adjacent nodes
		for (int i=0; i<f->edges.size(); ++i) {
			if (Colors[f->edges[i].v->id] != -1) {			// all colors of adjacent nodes, if not available
				availableColor[Colors[f->edges[i].v->id]] = false;      // mark the color as unavailable
			}	
		}

		// find the first available color, iterate through availability vector
		for (int i=0; i<V; ++i) {
			if (availableColor[i]) {
				Colors[f->id] = i;	// found available color, assign it
				break;
			}
		}

		// iterate through adjacent nodes again to reset the availability vector
		for (int i=0; i<f->edges.size(); ++i) {
			if (Colors[f->edges[i].v->id] != -1) {
				availableColor[Colors[f->edges[i].v->id]] = true;
			}
		}

	}

	return Colors;
}

int main() {

	// create a graph with V vertices
	vector<GraphVertex*> Graph(V);
	for (int i=0; i<V; ++i) {
		Graph[i] = new GraphVertex(i);
	}

	createGraph(&Graph);

	
	vector<int> Colors = greedyColoring(Graph);


	for (int i=0; i<Colors.size(); ++i) {
		cout << "Node: "<<i<<" assigned color: "<<Colors[i]<<endl;
	}

	sort(Colors.begin(), Colors.end());
	Colors.erase(unique(Colors.begin(), Colors.end()), Colors.end());
	cout << "Chromatic Number for the graph: "<<Colors.size() << endl;

	return 0;
}
