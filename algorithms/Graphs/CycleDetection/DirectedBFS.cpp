// KAHN'S ALGORITHM
// https://takeuforward.org/data-structure/detect-a-cycle-in-directed-graph-topological-sort-kahns-algorithm-g-23/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

bool cycleBFS(int V, vector<int> adj[]) {
    // CYCLE DETECTION IN DIRECTED GRAPH USING BFS : KAHN'S ALGORITHM : CAN ALSO GENERATE TOPOLOGICAL SORT
    
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

    vector<int>topo;         // generates the topological sort
    int count = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        count++;
        for(int v : adj[u]) {
            indegree[v]--;
            if(indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    return (count != V);      // if count==num then there is no cycle
    // if count < V or count > V then there is some cycle
}

bool hasCycle(vector<int>adjList[], int V) {
    // we need to check only once even if graph has multiple components.
    // even with multiple components, we are pushing each one of them with indegree = 0 at the start only. Hence if any component has cycle, its topo_count < #nodes_in_component, hence total_count < V, hence cycle.
    if(cycleBFS(V, adjList)) return true;        
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




