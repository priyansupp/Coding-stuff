#include<bits/stdc++.h>
using namespace std;


void DFSVisit(vector<int> &dfsofcomp, vector<int>adjList[], int u, vector<bool> &visited, vector<int> &dfswhole, int &nodes){
    visited[u] = true;
    nodes++;
    dfswhole.push_back(u);
    dfsofcomp.push_back(u);
    for(int v : adjList[u]){
        if(!visited[v]){
            DFSVisit(dfsofcomp, adjList, v, visited, dfswhole, nodes);
        }
    }
}

void DFS(int V, vector<int>adjList[]){
    int comp = 0;       // count of components
    vector<bool>visited(V, false);
    vector<int>dfswhole;
    for(int u = 0; u < V; u++){
        if(!visited[u]){     // graph may have disconnected components(or weakly connected in directed graph) and dfs on one component does not traverses rest. So this ensures all nodes are traversed, disconnected or not.
            comp++;
            int nodes = 0;
            vector<int>dfsofcomp;
            DFSVisit(dfsofcomp, adjList, u, visited, dfswhole, nodes);      // u here is source for the component
            cout << "This component has " << nodes << " nodes\n";
            for(int u : dfsofcomp) cout << u << " ";
            cout << '\n';
        }
    }
    cout << "The graph has total of " << comp << " components.\nDFS of whole graph :\n";
    for(int u : dfswhole) cout << u << " ";
    return;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adjList[V];         // undirected graph
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    DFS(V, adjList);

    return 0;
}

// GENERAL STRUCTURE OF DFS

// bool vis[1e7];
// void dfs(int vertex){
//     // Take action on vertex after entering the vertex

//     vis[vertex] = true;
//     for(int child : adjList[vertex]){
//         // Take action on child before entering the child node

//         if(vis[child]) continue;
//         dfs(child);         // Entering the child node

//         // Take action on child after exiting the child node
//     }

//     // Take action on vertex before exiting the vertex.
// }






