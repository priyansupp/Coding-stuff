#include<bits/stdc++.h>
using namespace std;

int bfs(vector<int>adj[], int S, bool vis[], vector<int> &c) {
    queue<int>q;
    q.push(S);
    vis[S] = true;
    int mini = c[S];
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(vis[v]) continue;
            q.push(v);
            vis[v] = true;
            mini = min(mini, c[v]);
        }
    }

    return mini;
}



int main() {
    int n, m;
    cin >> n >> m;
    vector<int>c(n + 1);
    for(int i = 1; i <= n; i++) cin >> c[i];
    vector<int>adj[n + 1];
    for(int i = 0 ;i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool vis[n + 1] = {false};
    long long total = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            total += (long long)bfs(adj, i, vis, c);
        }
    }
    cout << total;
    return 0;
}