#include<bits/stdc++.h>
using namespace std;

// BFS + SHORTEST PATH IN UNWEIGHTED UNDIRECTED GRAPH.

struct Ver{
    int pi, dist;       // dist: minimum distance from source to a particular vertex, i.e, shortest path for unit weight edges in undirected graph.
    char color;     // w - white - undiscovered. g - gray - discovered but unfinished. b - black - discovered and finished
};
vector<Ver>Vertex;

void BFS(int Source, int V, vector<int> adjList[]){
    for(int u = 0; u < V; u++){
        if(u == Source) continue;
        Vertex[u].color = 'w';
        Vertex[u].dist = INT_MAX;
        Vertex[u].pi = -1;
    }
    Vertex[Source].color = 'g';
    Vertex[Source].dist = 0;
    Vertex[Source].pi = -1;
    queue<int>q;
    q.push(Source);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adjList[u]){
            if(Vertex[v].color == 'w'){     // 'w' means not visited
                Vertex[v].color = 'g';      // when it's 'g' it means it is in the queue
                Vertex[v].dist = Vertex[u].dist + 1;        // level or dist.
                Vertex[v].pi = u;
                q.push(v);
            }
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

    BFS(0, V, adjList);
    for(int i = 0; i < V; i++){
        cout << "For vertex " << i << " the distance from source is " << Vertex[i].dist << " and color " << Vertex[i].color << "\n";
    }

    return 0;
}