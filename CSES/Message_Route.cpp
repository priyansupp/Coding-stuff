#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int>adj[n + 1];
    forr(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool vis[n + 1];
    int level[n + 1];
    int par[n + 1];
    memset(par, 0, sizeof(par));
    memset(level, 0, sizeof(level));
    memset(vis, false, sizeof(vis));
    queue<int>q;
    q.push(1);
    level[1] = 1;       // level[i] = number of nodes in simple shortest path from 1 to i.
    vis[1] = true;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(vis[v]) continue;
            vis[v] = true;
            par[v] = u;
            level[v] = level[u] + 1;
            q.push(v);
        }
    }
    if(vis[n]) {
        cout << level[n] << '\n';
        vector<int>ans;
        int i = n;
        while(i != 1) {
            ans.push_back(i);
            i = par[i];
        }
        ans.push_back(1);
        for(int i = level[n] - 1; i >= 0; i--) cout << ans[i] << " ";

    } else {
        cout << "IMPOSSIBLE";
    }
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}