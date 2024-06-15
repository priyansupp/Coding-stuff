// https://takeuforward.org/data-structure/detect-cycle-in-an-undirected-graph-using-bfs/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
bool vis[N];

// we start at source with its parent being -1 and perform bfs storing node and parent in queue. If at any point we strike at a node whose adjList contains a node which is already visited(other than the parent) then it must be visited by another path and hence must have a cycle. https://www.youtube.com/watch?v=A8ko93TyOns&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=7&t=26s
bool cycleBFS(int S, vector<int>adjList[], int V) {
    queue<pair<int, int>>q;
    q.push({S, -1});
    vis[S] = true;
    while (!q.empty()){
        pair<int, int> u = q.front();
        q.pop();
        for(int v : adjList[u.first]) {
            if(!vis[v]){
                q.push({v, u.first});
                vis[v] = true;
            } else if(v != u.second) {        // if v is already visited and but is not the parent of u then there is cycle
                return true;
            }
        }
    }
    return false;
}

bool hasCycle(vector<int>adjList[], int V) {
    for(int i = 0; i < V; i++) {                // for every component of graph
        if(!vis[i]) {
            if(cycleBFS(i, adjList, V)) return true;        // if the component has cycle return true.
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

// Another way: Intuition => V nodes can have at max V - 1 connections without forming a cycle
// For an undirected graph with V nodes, if it contains more than V - 1 edges, then it must have a cycle.
// To check for <= V - 1, we count the total number of components in the graph(let = a), then if the graph contains, V - a edges then it has no cycle, if more than V - a edges then it must have a cycle(it can't have less than V - a edges.)