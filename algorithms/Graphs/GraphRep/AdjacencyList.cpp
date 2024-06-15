#include<bits/stdc++.h>
using namespace std;


int main()
{
    int V, E;
    cin >> V >> E;

    // UNWEIGHTED GRAPH
    vector<int> adjList[V];         // array of vector(of ints)

    // adjList[0] = {1,3,6,5};      // node 0 is connected to 1,3,6,8
    // adjList[1] = {0,4,2};
    // adjList[2] = {4,6,7};
    // .
    // .
    // .
    // .
    // adjList[V - 1] = {5,6,8,9};

    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);            // (u, v) is new edge
        adjList[v].push_back(u);            // (v, u) is new edge... Only in undirected graph
    }

    // WEIGHTED GRAPH
    vector<pair<int, int>>adjListW[V];         // array of vector(of pair of ints). In pair, first is vertex, second is weight

    // adjList[0] = {{1, 54},{3, 47},{6, 90},{5, 83}};      // node 0 is connected to 1 and weight of 0-->1 is 54
    // adjList[1] = {{0, 54},{4, 27},{2, 32}};

    for(int i = 0; i < E; i++){
        int u, v, weight;
        cin >> u >> v >> weight;
        adjListW[u].push_back({v, weight});            // (u, v) is new edge
        adjListW[v].push_back({u, weight});            // (v, u) is new edge... Only in undirected graph
    }


    return 0;
}