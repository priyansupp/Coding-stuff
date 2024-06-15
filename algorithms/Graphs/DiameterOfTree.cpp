#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int>depth(N);
vector<int>adj[N];

// Diameter of a tree is the maximum distance(edges) between any two nodes. For two nodes being endpoints of diameter, maximum depth using any end point as root is the diameter of the tree.
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
//                                  |
//                                  14

// The diameter is 12-8-5-2-1-3-4-10-11 = 8(nodes)

// 14 13
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
// 10 13

void dfs(int vertex, int parent = -1){

    for(int child : adj[vertex]){
        if(child == parent) continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }

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

    // Method 1:
    // For each node, Run dfs using that node as root and find the maximum depth for that root. Take maximum over all maximum depths, that'll be diameter. TC = O(V^2)
    // using 1 as root, maxdepth = 5. using 5 as root, maxdepth = 7. using 12(or 14) as root, maxdepth = 9

    // Method 2:
    // Take any node as root and find the node which gives maximum depth. That node will necessarily be one end of diameter(see proof in clrs).
    // using 1 as root, 14 gives maximumdepth(of 5), therefore 14 is one end of diameter. Now simply run dfs using 14 as root and find maximum depth, that'll be diameter.

    int root = 1;
    dfs(root);
    int max_depth = 0, max_depth_node = root;
    for(int i = 0; i < V; i++){
        if(max_depth < depth[i]){
            max_depth = depth[i];
            max_depth_node = i;             // node which has maximum depth
        }
        depth[i] = 0;       // resetting depth array for later use.
    }
    root = max_depth_node;
    dfs(root);
    cout << "Diameter of the tree is : " << *max_element(depth.begin(), depth.begin() + V);

    return 0;
}