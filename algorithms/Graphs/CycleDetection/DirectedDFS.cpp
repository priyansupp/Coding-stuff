// https://takeuforward.org/data-structure/detect-a-cycle-in-directed-graph-using-dfs/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
bool vis[N];
bool dfsVis[N];         // keeps track of visited nodes in that particular dfs call

bool cycleDFS(int u, vector<int> adj[]) {
    vis[u] = 1;
    dfsVis[u] = 1;
    for(int v : adj[u]) {
        if(!vis[v]) {
            if(cycleDFS(v, adj)) return 1;
        } else if (dfsVis[v]) {
            return 1;
        }
    }
    dfsVis[u] = 0;
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




