#include<bits/stdc++.h>
using namespace std;

// Spanning tree - a tree of a graph in which we can travel from any vertex to any other vertex and has exactly V vertices and V - 1 edges.
// MST - a spanning tree with minimum sum of weights of all the edges.
// Two algos to generate MST - Prim's | O(ElogV) and Kruskal's | O(ElogV) (both work only on undirected graphs).

vector<int> Prims(vector<pair<int, int>> adjList[], int V){
    vector<int>MST(V, false);
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> adjList[V];         // undirected graph
    for(int i = 0; i < E; i++){
        int u, v, weight;
        cin >> u >> v >> weight;
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    return 0;
}
