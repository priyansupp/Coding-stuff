#include<bits/stdc++.h>
using namespace std;


int main()
{
    int V, E;               // number of vertices and number of edges
    cin >> V >> E;

    // UNWEIGHTED GRAPH
    int adj[V][V] = {0};    // Adjacency matrix with no edges set
    for(int i = 0; i < E; i++){
        int u, v;           // taking vertices corresponding to each edge.
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;      // only if the graph is undirected
    }

    // WEIGHTED GRAPH
    // int adj[V][V] = {INFINITY};            // Adjacency matrix with no edges set. Infinity denotes there's no edge between two vertices
    // for(int i = 0; i < E; i++){
    //     int u, v, weight;            // taking vertices and weight corresponding to each edge.
    //     cin >> u >> v >> weight;
    //     adj[u][v] = weight;
    //     adj[v][u] = weight;          // only if the graph is undirected
    // }


    return 0;
}