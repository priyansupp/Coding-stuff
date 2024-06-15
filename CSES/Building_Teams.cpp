#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

bool dfs(int color[], bool vis[], vector<vector<int>>&adj, int u) {
    vis[u] = true;
    bool ans = true;
    for(int v : adj[u]) {
        if(vis[v]) {
            if(color[v] == color[u]) return false;
            continue;
        }
        color[v] = (color[u] == 1) ? 2 : 1;
        ans &= dfs(color, vis, adj, v);
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    int u, v;
    forr(i, 0, m) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool vis[n + 1];
    int color[n + 1];
    memset(vis, false, sizeof(vis));
    memset(color, 0, sizeof(color));
    bool flag = true;
    forr(i, 1, n + 1) {
        if(!vis[i]) {
            color[i] = 1;
            if(!dfs(color, vis, adj, i)) {
                flag = false;
                break;
            }
        }
    }
    if(!flag) cout << "IMPOSSIBLE";
    else {
        forr(i, 1, n + 1) cout << color[i] << " ";
    }
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}