#include<bits/stdc++.h>
using namespace std;


void DFS(vector<int>adjList[], int u, vector<bool> &visited, stack<int> &st){
    visited[u] = true;
    for(int v : adjList[u]){
        if(!visited[v]){
            DFS(adjList, v, visited, st);
        }
    }
    st.push(u);
    // node at the end gets inserted(with greater in-degree) in the vector first, thus while reversing, it'd come at the start.
    // for any edge (u, v) : u -> v, recursion on u leads to v and thus, first v gets pushed in toposort then u. While reversing, u comes before v.
}


vector<int> TopoSort(int V, vector<int>adjList[]){
    vector<bool>visited(V, false);
    stack<int>st;
    for(int u = 0; u < V; u++){
        if(!visited[u]){     // graph may have disconnected components(or weakly connected in directed graph) and dfs on one component does not traverses rest. So this ensures all nodes are traversed, disconnected or not.
            DFS(adjList, u, visited, st);
        }
    }
    vector<int>toposort;
    while(!st.empty()) {
        toposort.push_back(st.top());
        st.pop();
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