#include<bits/stdc++.h>
using namespace std;
#define forr(i, a, b) for(int i = a; i < b; i++)

// we can even form a dp[i] = EV of subtree rooted at i
// dp[i] = 1 + SUM(dp[children(i)])

long double dfs(vector<int> adj[], int u, bool vis[]) {
    vis[u] = true;
    long double val = 0;
    int numChildren = 0;
    for(int v : adj[u]) {
        if(vis[v]) continue;
        numChildren++;
        val += dfs(adj, v, vis);
    }
    if(numChildren == 0) return 0;
    return (val / numChildren) + 1;             // this extra 1 is the edge cost from children to node, be it any path this cost will add up.
}

int main() {
    int n;
    cin >> n;
    vector<int>adj[n + 1];
    forr(i, 1, n + 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int totalSum = 0, countLeaf = 0;
    bool vis[n + 1];
    memset(vis, false, sizeof(vis));
    cout << setprecision(15);
    long double ans = dfs(adj, 1, vis);
    cout << ans; 
    return 0;
}