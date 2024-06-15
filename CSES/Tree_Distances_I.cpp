#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i, a, b) for(int i = a; i < b; i++)

// Calculate the diameter and its two ends
// for any node, the maximum distance to any node must pass through diameter and end at either end of the diameter.
// suppose xi->x1->x2--->xe be the diameter
// if possible let s->s1->s2...->se be the maximum distance path of node s, not touching any of the nodes on the diameter(if it does, then it must go on either ends only, else it violates that diameter is the longest maximum distance path)
// minimum of all maximal possible paths of s going through diameter(to its end) would be diameter/2(when s is in center). As assumed, the path s->s1->s2---se would be longer than diameter/2
// Consider a simple path from either of diameter ends to s, i.e xi->s or xe->s whichever is longer(say, xi->s). Then as s->se does not touches the diameter even once, hence we can expand the path xi->s->se and with total length of length(xi->s) + length(s->se), both greater than diameter/2 and hence the sum > diameter which violates that diameter is the longest(while we found a path xi->s->se longer than diameter).

int bfs(int S, int n, int *dist, vector<int>adj[]) {
    bool vis[n + 1];
    memset(vis, false, sizeof(vis));
    queue<int>q;
    q.push(S);
    vis[S] = true;
    int node = S;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        node = u;                       // last node to pop is the one end of the diameter
        for(int v : adj[u]) {
            if(vis[v]) continue;
            q.push(v);
            vis[v] = true;
            dist[v] = dist[u] + 1;
        }
    }
    return node;
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
    int distance1[n + 1], distance2[n + 1];
    memset(distance1, 0, sizeof(distance1));
    memset(distance2, 0, sizeof(distance2));
    int diameterEnd1 = bfs(1, n, distance1, adj);                       // this bfs to find diameterEnd1

    memset(distance1, 0, sizeof(distance1));
    int diameterEnd2 = bfs(diameterEnd1, n, distance1, adj);            // this bfs to find diameterEnd2 and calculate distance of each node from diameterEnd1

    bfs(diameterEnd2, n, distance2, adj);                               // this bfs to calculate distance of each node from diameterEnd2

    for(int i = 1; i <= n; i++) {
        cout << max(distance1[i], distance2[i]) << ' ';
    }
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}