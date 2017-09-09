#include "header.hpp"
using namespace std;

#define V 5

enum Status {not_visited, visiting, visited};

class GraphVertex {
	public:
		int src;
		Status status = not_visited;
		// edges - vector of pointer to a graphvertex
		vector<pair<GraphVertex*,int>> edges;
		GraphVertex(int s) {
			src = s;
		}
};

void dfs(GraphVertex* g) {

	// if currently visiting, simply return
	if (g->status==visiting) {
		return;
	}

	// mark node as visiting
	g->status = visiting;

	cout<<"visiting : " <<g->src<<endl;
		
	// iterate over the adjacency list
	vector<pair<GraphVertex*,int>>::iterator itr;
	for (itr=g->edges.begin(); itr!=g->edges.end(); ++itr) {
		if (itr->first->status!=visited) {
			dfs(itr->first);
		}
	}

	// mark node as visited
	g->status = visited;
}


void addEdge(GraphVertex* u, GraphVertex* v, int weight) {
	u->edges.emplace_back(make_pair(v,weight));
}

void printAdjList(GraphVertex* u) {

	cout <<"Vertex : "<<u->src<<" ==> ";
	vector<pair<GraphVertex*, int>>::iterator itr;
	for (itr=u->edges.begin();itr!=u->edges.end();++itr) {
		cout << itr->first->src << " --> ";
	}
	cout << endl << endl;
}

int main() {

	// create graph using adjacency list
	vector<GraphVertex*> Graph(V);
	for (int i=0; i<V; ++i) {
		Graph[i] = new GraphVertex(i);
	}

	cout << "Created Graph Vertices" << endl;

	addEdge(Graph[0], Graph[4], 1);
	addEdge(Graph[0], Graph[1], 1);
	addEdge(Graph[1], Graph[4], 1);
	addEdge(Graph[1], Graph[3], 1);
	addEdge(Graph[1], Graph[2], 1);
	addEdge(Graph[1], Graph[0], 1);
	addEdge(Graph[2], Graph[3], 1);
	addEdge(Graph[2], Graph[1], 1);
	addEdge(Graph[3], Graph[4], 1);
	addEdge(Graph[3], Graph[2], 1);
	addEdge(Graph[3], Graph[1], 1);
	addEdge(Graph[4], Graph[3], 1);
	addEdge(Graph[4], Graph[1], 1);
	addEdge(Graph[4], Graph[0], 1);

	cout << "created graph successfully " << endl;
	for (int i=0; i<V; ++i) {
		printAdjList(Graph[i]);
	}

	// perform depth first search	
	dfs(Graph[0]);

/*
	for (int i=0; i<V; ++i) {
		if (Graph[i]->status==not_visited) {
			cout <<Graph[i]->src<<endl;
			dfs(Graph[i]);
		}
	}
*/

	// start dfs from vertex 0
	return 0;
}
