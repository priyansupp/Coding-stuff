#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adjList[N];
vector<bool>visited(N);
int ShortestPath[N];

// BFS FOR A GRAPH CONTAINING MULTIPLE COMPONENT
vector<int> BFS(int V){
    vector<int>bfswhole;            // to store all the visited nodes in order of their visitance.
    int comp;                       // count of components
    for(int i = 0; i < V; i++){     // graph may have disconnected components(or weakly connected in directed graph) and bfs on one component does not traverses rest. So this ensures all nodes are traversed, disconnected or not.
        int nodes = 0;              // to get number of nodes in a component.
        vector<int>bfsofcomp;       // bfs in that component.
        if(!visited[i]){            // Each 'if' runs for a component of the graph. For each component, the source node is i.
            comp++;
            queue<int>q;
            q.push(i);              // source of each component is pushed in queue
            visited[i] = true;      // visited array for source(of each component) becomes true
            while(!q.empty()){      // All the nodes(in a component) are popped out of queue exactly once, hence we can manipulate with nodes, right in next 2 lines.
                int u = q.front();
                q.pop();
                bfsofcomp.push_back(u);       // nodes visited
                bfswhole.push_back(u);        // nodes visited
                nodes++;
                for(int v : adjList[u]){
                    if(!visited[v]){
                        q.push(v);
                        visited[v] = true;      // visited[i] becomes true as soon as it is inserted in the queue(and never inserted again).
                        ShortestPath[v] = ShortestPath[u] + 1;
                    }
                }
            }
        }
        cout << "This component has " << nodes << " nodes.\n";      // nodes = bfsofcomp.size();
        for(int u : bfsofcomp) cout << u << " ";
        cout << '\n';
    }
    return bfswhole;
}

// BFS is Level order traversal.
// SIMPLE BFS FOR A GRAPH CONTAINING SINGLE COMPONENT
// int level[N];                       // All levels initialized to 0, level[source] = 0;
// For undirected unweighted graph, level[i] is Shortest Path from source to i. (level[source] = 0)
// void bfs(int source){
//     // vector<int>bfsarray;
//     queue<int>q;
//     q.push(source);
//     while(!q.empty()){
//         int u = q.front();
//         q.pop();
//         // cout << u << " ";        // prints the bfs order
//         // bfsarray.push_back(u);   // to get the bfs order in array
//         for(int v : adjList[u]){
//             if(!visited[v]){
//                 q.push(v);
//                 visited[v] = true;
//                 level[v] = level[u] + 1;
//             }
//         }
//     }
// }

int main()
{
    int V, E;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);         // undirected graph
    }

    vector<int>bfs =  BFS(V);
    for(int i : bfs){
        cout << i << " ";
    }

    return 0;
}