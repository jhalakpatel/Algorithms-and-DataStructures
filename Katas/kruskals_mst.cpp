#include "header.hpp"

using namespace std;

#define V 4

/*
 *	TIME COMPLEXITY : O(ELogE) - sorting E edges, Union Find : O(LogV) and for E edges : O(ELogV)
 *	E = O(V2) at max, O(ELogE) == O(ELogV)
 */

struct GraphVertex {
	int id;
	struct Edge {
		GraphVertex* src;
		GraphVertex* dest;
		int weight;
	};
	vector<Edge> edges;
	GraphVertex(int tid) {
		id = tid;
	}
};

void addEdge(GraphVertex *u, GraphVertex *v, int weight) {
	u->edges.emplace_back(GraphVertex::Edge{u, v, weight});
	v->edges.emplace_back(GraphVertex::Edge{v, u, weight});
}

void CreateGraph(vector<GraphVertex*> *gptr) {
	vector<GraphVertex*> &Graph = *gptr;
	addEdge(Graph[0], Graph[1], 10);
	addEdge(Graph[1], Graph[3], 15);
	addEdge(Graph[3], Graph[2], 4);
	addEdge(Graph[2], Graph[0], 6);
	addEdge(Graph[0], Graph[3], 5);
}


int find(int s, vector<int> *pSetPtr){
	vector<int> &pSet = *pSetPtr;
	if (pSet[s]==-1) return s;
	return find(pSet[s], &pSet);
}

void Union(int src, int dest, vector<int> *pSetPtr) {
	vector<int> &pSet = *pSetPtr;	
	pSet[src] = dest;
}

bool HasCycle(GraphVertex::Edge e, vector<int> *pSet) {
	int src = find(e.src->id, pSet);
	int dest = find(e.dest->id, pSet);

	if (src==dest) return true;
	Union(src, dest, pSet);
	return false;
}

struct greater_then_weight {

	bool operator() (GraphVertex::Edge e1, GraphVertex::Edge e2) {
		return e1.weight <= e2.weight;
	}

};

vector<GraphVertex::Edge> KruskalsMST(vector<GraphVertex::Edge> GraphEdges) {

	// sort the egdes with smallest to largest edge weight	
	sort(GraphEdges.begin(), GraphEdges.end(), greater_then_weight()); 

	// create parentSet 
	vector<int> parentSet(V, -1);

	vector<GraphVertex::Edge> MST;

	// iterate over the smallest to largest weight
	for (int i=0; i<GraphEdges.size(); ++i) {
		if (MST.size()!=V-1) {
			// if does not have cycle	
			if (!HasCycle(GraphEdges[i], &parentSet)) {
				MST.emplace_back(GraphEdges[i]);	
			}
		} else {
			// if the MST contains V-1 edges, tree is completed
			break;
		}
	}

	return MST;
}

int main() {

	vector<GraphVertex*> Graph(V);
	for (int i=0; i<V; ++i) {
		Graph[i] = new GraphVertex(i);
	}

	//CreateGraph(&Graph);

	// create an alternate graph representation with graph having src, dest and edge weight only
	vector<GraphVertex::Edge> GraphEdges;
	GraphEdges.emplace_back(GraphVertex::Edge{Graph[0], Graph[1], 10});
	GraphEdges.emplace_back(GraphVertex::Edge{Graph[1], Graph[3], 15});
	GraphEdges.emplace_back(GraphVertex::Edge{Graph[3], Graph[2], 4});
	GraphEdges.emplace_back(GraphVertex::Edge{Graph[2], Graph[0], 6});
	GraphEdges.emplace_back(GraphVertex::Edge{Graph[3], Graph[0], 5});

	vector<GraphVertex::Edge> MST = KruskalsMST(GraphEdges);

	// print minimum spanning tree
	cout << "Edges of Minimum Spanning Tree -- "<< endl;
	int sum = 0;
	for (int i=0; i<MST.size(); ++i) {
		GraphVertex::Edge e = GraphVertex::Edge{MST[i]};
		cout << e.src->id << " ---> " << e.dest->id << endl;
		sum += e.weight;
	}

	cout << endl;
	cout << "Total Edge Weight Sum : "<<sum<<endl;

	return 0;
}
