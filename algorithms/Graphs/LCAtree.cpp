#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int>adj[N];
int par[N];         // stores parent of each vertex

void dfs(int vertex, int parent = -1){
    par[vertex] = parent;               // this will store par[root] = -1;
    for(int child : adj[vertex]){
        if(child == parent) continue;
        dfs(child, vertex);
    }
}

vector<int> Path(int node){         // returns vector/path from root to that node.
    vector<int> ans;
    while(node != -1){              // break when parent(node = par[node] in prev iteration) is -1.
        ans.push_back(node);
        node = par[node];
    }
    reverse(ans.begin(), ans.end());
    return ans;
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
    int root = 0;           // given root = 0. LCA changes with change in root.
    dfs(root);
    int x, y;
    while(1){
        cin >> x >> y;
        vector<int>path1 = Path(x), path2 = Path(y);
        int i = 0, min_len = min(path1.size(), path2.size());
        while(path1[i] == path2[i] && i < min_len){
            i++;
        }
        cout << "LCA of " << x << " and " << y << " is " << path1[i - 1] << '\n';
    }
    
    return 0;
}




// 1 based indexing of nodes:
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

// For LCA of 6 and 12, store the path(using dfs) from root to 6 and root to 12 and find the last matching node in the path
// root to 6 : 1-2-5-6
// root to 12 : 1-2-5-8-12
// Hence LCA is 5

// Taken 0 based indexing of nodes.
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