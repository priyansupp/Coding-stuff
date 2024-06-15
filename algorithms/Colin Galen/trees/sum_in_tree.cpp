#include<bits/stdc++.h>
using namespace std;
#define forr(i, a, b) for(int i = a; i < b; i++)


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