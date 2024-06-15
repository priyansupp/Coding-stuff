// https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-dfs/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
bool vis[N];

bool cycleDFS(int u, vector<int> adj[], int parent = -1) {
    vis[u] = 1;
    for(int v : adj[u]) {
        if(!vis[v]) {
            if(cycleDFS(v, adj)) return 1;
        } else if (v != parent) {        // if v is already visited and but is not the parent of u then there is cycle
            return 1;
        }
    }
    return 0;
}

bool hasCycle(vector<int>adjList[], int V) {
    for(int i = 0; i < V; i++) {                // for every component of graph
        if(!vis[i]) {
            if(cycleDFS(i, adjList)) return true;        // if the component has cycle return true.
        }
    }
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<int>adjList[N];
    for(int i = 1; i <= E; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    if(hasCycle(adjList, V)) cout << "Graph has cycle";
    else cout << "Graph does not have cycle";
    return 0;
}




