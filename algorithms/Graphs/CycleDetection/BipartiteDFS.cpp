#include<bits/stdc++.h>
using namespace std;
// Bipartite graph : A graph which can be covered using 2 colors such that no two adjacent nodes have same color.
// A graph with odd length cycle can never be bipartite, else it is a bipartite(even length cycle or without cycle)
const int N = 1e5;
int color[N];
vector<int>adj[N];

bool checkBipartComp(int u) {           // dfs
    for(int v : adj[u]) {
        if(color[v] == -1) {
            color[v] = (color[u] == 1) ? 2 : 1;
            if(!checkBipartComp(v)) {
                return false;
            }
        } else if(color[v] == color[u]) {       // if adjacent node is colored the same as 'u' then it is definitely not biparitite.
            return false;
        }
    }
    return true;
}

bool isBipartite(int V){
    memset(color, -1, sizeof(color));   // -1: not colored yet, 1: color1, 2: color2
    for(int i = 1; i <= V; i++) {       // checking for all the components in the graph
        if(color[i] == -1) {            // means the node is still uncolored hence unvisited. color array does the work of visited array also.
            color[i] = 1;               // coloring the source node as 1
            if(!checkBipartComp(i)) return false;       // if any component returns false then whole graph is non-bipartite.
        }
    }
    return true;
}

int main()
{
    int V, E;
    cin >> V >> E;
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(isBipartite(V)) cout << "Graph is bipartite";
    else cout << "Graph is not bipartite";

    return 0;
}