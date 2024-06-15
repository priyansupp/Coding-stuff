#include<bits/stdc++.h>
using namespace std;

// SHORTEST PATH IN WEIGHTED DIRECTED ACYCLIC GRAPH.

void DFSVisit(vector<pair<int, int>>adjList[], int u, vector<bool> &visited, vector<int> &toposort){
    visited[u] = true;
    for(pair<int, int> v : adjList[u]){
        if(!visited[v.first]){
            DFSVisit(adjList, v.first, visited, toposort);
        }
    }
    toposort.push_back(u);
}


vector<int> TopSort(int V, vector<pair<int, int>>adjList[]){
    vector<bool>visited(V, false);
    vector<int>toposort;
    for(int u = 0; u < V; u++){
        // multiple components
        if(!visited[u]){
            DFSVisit(adjList, u, visited, toposort);
        }
    }
    reverse(toposort.begin(), toposort.end());
    return toposort;
}

vector<int> ShortestPath(int S, int V, vector<pair<int, int>>adjList[]){
    vector<int>SP(V, INT_MAX);  // all weights from source to vertices assigned as infinity
    vector<int>topSort = TopSort(V, adjList);   // we will visit the vertices in topologicallly sorted order(any sort).
    SP[S] = 0;      // distance from source to source is 0
    for(int u : topSort){
        for(pair<int, int> v : adjList[u]){     // for each vertex visited, we'll visit its neighbors and assign lowest weight to each neighbor of u.
            SP[v.first] = min(SP[v.first], SP[u] + v.second);       // v = {u, weight}; here weight is the weight of the path from u to v.
        }
    }
    return SP;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> adjList[V];         // directed acyclic graph
    for(int i = 0; i < E; i++){
        int u, v, weight;
        cin >> u >> v >> weight;
        adjList[u].push_back({v, weight});
    }

    vector<int>SPath = ShortestPath(0, V, adjList);     // SPath contains minimum weight of path to reach from source to any vertex. Source here is node[0]
    for(int u : SPath){
        cout << u << " ";
    }

    return 0;
}
