#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int height[N], depth[N];
vector<int>adj[N];

// In tree, visited array is not required for dfs, as it does not contain cycle and the parent case can be handled easily by passing parent parameter. If for the vertex, child == parent of the vertex, we have to skip(because we have already visited the parent (going up to down), no need to visit again). For any vertex, we just have to go down the tree.
void dfs(int vertex, int parent = -1){    // default value when the dfs starts at root(root's parent DNE)
    // after entering vertex
    for(int child : adj[vertex]){
        if(child == parent) continue;

        depth[child] = depth[vertex] + 1;       // depth is built while going top to bottom in the tree.
        // before entering child
        dfs(child, vertex);    // entering child
        // after exiting child
        height[vertex] = max(height[vertex], height[child] + 1);        // height is built while coming up, i.e bottom to top.
        // Subtree queries are also built bottom to top.
        
    }
    // before exiting vertex
}

int main()
{
    int V, E;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // using base 0 indexing(0 - (V - 1) are nodes).
    int root = 0;
    depth[root] = 0;
    dfs(root);
    for(int i = 0; i < V; i++){
        cout << "Height of node " << i << " is " << height[i] << " and depth " << depth[i] << '\n';
    }
    return 0;
}


// A SAMPLE TREE - GRAPH(does not have cycle, rooted at 1) AND ITS ADJACENCY LIST REPRESENTATION:

//                              1
//                         /    |    \
//                     2        3     13
//               /              |            
//         5                    4
//     /   |   \             /     \
// 6       7      8         9       10
//                |                 |
//                12                11

// depth of all root node is 0, height of all leaf nodes is always 0, and rest gets updated through maximum of its leaf + 1.
// height[5] = max(height[6], height[7], height[8]) + 1


// 13 12
// 0 1
// 0 2
// 0 12
// 1 4
// 2 3
// 4 5
// 4 6
// 4 7
// 7 11
// 3 8
// 3 9
// 9 10
