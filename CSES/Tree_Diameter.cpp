#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

// METHOD II
// One easy to implement solution is using 2 Breadth First Searches (BFS). Start a BFS with a random node and store the last node encountered before search ends. This last node will definitely be one of the ends of the diameter (Why?). Now run a second BFS from this node and you will end on the other end of the diameter. 
// level of a node in bfs is its depth. last exiting node has the highest level and hence the greatest depth

// METHOD III
// calculate height of each node using dfs and then traverse through each node
// dp[node] = 1 + height[node->left] + height[node->right]

void dfs(int u, vector<int>adj[], int depth[], bool vis[]) {
    vis[u] = true;
    for(int v : adj[u]) {
        if(vis[v]) continue;
        depth[v] = depth[u] + 1;
        dfs(v, adj, depth, vis);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int>adj[n + 1];
    forr(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool vis[n + 1];
    int depth[n + 1];
    memset(depth, 0, sizeof(depth));
    memset(vis, false, sizeof(vis));
    dfs(1, adj, depth, vis);
    int maxDepth = 0, maxDepthNode = 1;
    forr(i, 1, n + 1) {
        if(maxDepth < depth[i]) {
            maxDepth = depth[i];
            maxDepthNode = i;
        }
        depth[i] = 0;
        vis[i] = false;
    }
    dfs(maxDepthNode, adj, depth, vis);
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, depth[i]);
    cout << ans;
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}