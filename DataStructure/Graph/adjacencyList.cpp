#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjList[], int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}

int main() {
    vector<int> adjList[5];
    addEdge(adjList, 0, 1); 
    addEdge(adjList, 0, 4); 
    addEdge(adjList, 1, 2); 
    addEdge(adjList, 1, 3); 
    addEdge(adjList, 1, 4); 
    addEdge(adjList, 2, 3); 
    addEdge(adjList, 3, 4);
    printGraph(adjList, 5);


    return 0;
}