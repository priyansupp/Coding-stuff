#include<bits/stdc++.h>
using namespace std;


struct Ver{
    int pi;
    char color;     // w - white - undiscovered. g - gray - discovered but unfinished. b - black - discovered and finished
};
vector<Ver>Vertex;

void DFSVisit(vector<int>adjList[], int u){
    Vertex[u].color = 'g';
    for(int v : adjList[u]){
        if(Vertex[v].color == 'w'){
            Vertex[v].pi = u;
            DFSVisit(adjList, v);
        }
    }
}


void DFS(int V, vector<int>adjList[]){
    for(int u = 0; u < V; u++){     // coloring all nodes unvisited
        Vertex[u].color = 'w';      // 'w' - unvisited, 'g' - visited but not compeleted, 'b' - visited and completed
        Vertex[u].pi = -1;
    }

    // DFS FOR MULTIPLE COMPONENTS
    for(int u = 0; u < V; u++){
        if(Vertex[u].color == 'w'){     // graph may have disconnected components(or weakly connected in directed graph) and dfs on one component does not traverses rest. So this ensures all nodes are traversed, disconnected or not.
            DFSVisit(adjList, u);
        }
        Vertex[u].color = 'b';
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    Vertex.resize(V);
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