#include <iostream>
#include "MST.cpp"

using namespace std;

// Driver program to test above functions
int main()
{
    /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    MST graph(V,E);
 
 
    // add edge 0-1
    graph.addEdge(0, 0, 1, 10);
		
    // add edge 0-2
    graph.addEdge(1, 0, 2, 6);
    
    // add edge 0-3
    graph.addEdge(2, 0, 3, 5);
		
    // add edge 1-3
    graph.addEdge(3, 1, 3, 15);
		
    // add edge 2-3
    graph.addEdge(4, 2, 3, 4);

	cout << "Done creating the network " << endl;
		
    graph.KruskalMST();

	// print the contents of result[] to display the built MST
    cout << "Following are the edges in the constructed MST : "<< endl;
    
	for (int i = 0; i < V-1; ++i) {
        cout << graph.MSTVec[i].source << " ---> " << graph.MSTVec[i].dest << " === " <<  graph.MSTVec[i].weight << endl;
	}

    return 0;
}
