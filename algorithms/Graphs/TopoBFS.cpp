#include<bits/stdc++.h>
using namespace std;

vector<int> TopoSort(int V, vector<int>adj[]){
    // TOPOSORT USING BFS : KAHN'S ALGORITHM : CAN ALSO BE USED FOR CYCLE DETECTION
    
    // there is no need to run for multiple disconnected componenets, as even if components are disconnected, we are going to each vertex and simply including it in sort if indegree == 0.
    vector<int>toposort;
    int indegree[V];
    memset(indegree, 0, sizeof indegree);
    for(int i = 0; i < V; i++) {
        for(int v : adj[i]) {
            indegree[v]++;
        }
    }

    queue<int>q;
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int>toposort;         // generates the topological sort
    int count = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        toposort.push_back(u);
        count++;
        for(int v : adj[u]) {
            indegree[v]--;
            if(indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    return toposort;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adjList[V];         // directed acyclic graph
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    vector<int>toposort = TopoSort(V, adjList);
    for(int u : toposort){
        cout << u << " ";
    }

    return 0;
}